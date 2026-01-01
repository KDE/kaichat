/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatconfiguresettingsdialog.h"
#include "kaichat_widget_debug.h"
#include "kaichatconfigureaccessibilitywidget.h"
#include "kaichatconfigurefontwidget.h"
#include "kaichatconfiguregeneralwidget.h"
#include "kaichatconfigureinstanceswidget.h"
#include "kaichatconfigurespellcheckingwidget.h"

#include <KLocalizedString>
#include <KSharedConfig>
#include <KWindowConfig>
#include <QPushButton>
#include <QWindow>
#include <TextAutoGenerateText/TextAutoGenerateTextConfigurePluginsWidget>

#if HAVE_KUSERFEEDBACK
#include "kaichatconfigureuserfeedbackwidget.h"
#endif

namespace
{
const char myConfigGroupName[] = "KAIChatConfigureSettingsDialog";
}
using namespace Qt::Literals::StringLiterals;
KAIChatConfigureSettingsDialog::KAIChatConfigureSettingsDialog(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : KPageDialog(parent)
    , mConfigureGeneralWidget(new KAIChatConfigureGeneralWidget(manager, this))
    , mInstancesManagerWidget(new KAIChatConfigureInstancesWidget(manager, this))
    , mConfigurePluginsWidget(new TextAutoGenerateText::TextAutoGenerateTextConfigurePluginsWidget(this))
    , mConfigureFontWidget(new KAIChatConfigureFontWidget(this))
    , mConfigureSpellCheckingWidget(new KAIChatConfigureSpellCheckingWidget(this))
#if HAVE_TEXT_TO_SPEECH
    , mConfigureAccessibilityWidget(new KAIChatConfigureAccessibilityWidget(this))
#endif
#if HAVE_KUSERFEEDBACK
    , mConfigureUserFeedBackWidget(new KAIChatConfigureUserFeedbackWidget(this))
#endif
{
    setWindowTitle(i18nc("@title:window", "Configure KAIChat"));
    setFaceType(KPageDialog::List);

    const QString generalPageName = i18nc("@title General page name", "General");
    mConfigureGeneralWidgetPage = new KPageWidgetItem(mConfigureGeneralWidget, generalPageName);
    mConfigureGeneralWidgetPage->setIcon(QIcon(u":/kaichat/kaichat.svg"_s));
    addPage(mConfigureGeneralWidgetPage);

    const QString fontPageName = i18nc("@title General page name", "Font");
    mConfigureFontWidgetPage = new KPageWidgetItem(mConfigureFontWidget, fontPageName);
    mConfigureFontWidgetPage->setIcon(QIcon::fromTheme(u"preferences-desktop-font"_s));
    addPage(mConfigureFontWidgetPage);

    const QString instancesPageName = i18nc("@title Instances page name", "Instances");
    mConfigureInstancesWidgetPage = new KPageWidgetItem(mInstancesManagerWidget, instancesPageName);
    mConfigureInstancesWidgetPage->setIcon(QIcon::fromTheme(u"preferences-desktop-theme"_s));
    addPage(mConfigureInstancesWidgetPage);

    const QString spellCheckPageName = i18nc("@title Preferences page name", "Spell Checking");
    mConfigureSpellCheckWidgetPage = new KPageWidgetItem(mConfigureSpellCheckingWidget, spellCheckPageName);
    mConfigureSpellCheckWidgetPage->setIcon(QIcon::fromTheme(u"tools-check-spelling"_s));
    addPage(mConfigureSpellCheckWidgetPage);
#if HAVE_TEXT_TO_SPEECH
    const QString textToSpeechPageName = i18nc("@title Preferences page name", "Accessibility");
    mConfigureTextToSpeechWidgetPage = new KPageWidgetItem(mConfigureAccessibilityWidget, textToSpeechPageName);
    mConfigureTextToSpeechWidgetPage->setIcon(QIcon::fromTheme(u"preferences-desktop-accessibility"_s));
    addPage(mConfigureTextToSpeechWidgetPage);
#endif

    const QString pluginsPageName = i18nc("@title Instances page name", "Plugins");
    mConfigurePluginsWidgetPage = new KPageWidgetItem(mConfigurePluginsWidget, pluginsPageName);
    mConfigurePluginsWidgetPage->setIcon(QIcon::fromTheme(u"preferences-plugin"_s));
    addPage(mConfigurePluginsWidgetPage);

#if HAVE_KUSERFEEDBACK
    const QString userFeedBackPageName = i18nc("@title Preferences page name", "User Feedback");
    mConfigureUserFeedBackWidgetPage = new KPageWidgetItem(mConfigureUserFeedBackWidget, userFeedBackPageName);
    mConfigureUserFeedBackWidgetPage->setIcon(QIcon::fromTheme(u"preferences-other"_s));
    addPage(mConfigureUserFeedBackWidgetPage);
#endif

    buttonBox()->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::RestoreDefaults);

    connect(buttonBox()->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &KAIChatConfigureSettingsDialog::slotAccepted);
    connect(buttonBox()->button(QDialogButtonBox::Cancel), &QPushButton::clicked, this, &KAIChatConfigureSettingsDialog::reject);
    connect(buttonBox()->button(QDialogButtonBox::RestoreDefaults), &QPushButton::clicked, this, &KAIChatConfigureSettingsDialog::slotRestoreDefaults);
    readConfig();
    load();
}

KAIChatConfigureSettingsDialog::~KAIChatConfigureSettingsDialog()
{
    writeConfig();
}

void KAIChatConfigureSettingsDialog::readConfig()
{
    create(); // ensure a window is created
    windowHandle()->resize(QSize(800, 600));
    const KConfigGroup group(KSharedConfig::openStateConfig(), QLatin1StringView(myConfigGroupName));
    KWindowConfig::restoreWindowSize(windowHandle(), group);
    resize(windowHandle()->size()); // workaround for QTBUG-40584
}

void KAIChatConfigureSettingsDialog::writeConfig()
{
    KConfigGroup group(KSharedConfig::openStateConfig(), QLatin1StringView(myConfigGroupName));
    KWindowConfig::saveWindowSize(windowHandle(), group);
}

void KAIChatConfigureSettingsDialog::slotAccepted()
{
    mConfigureGeneralWidget->save();
    mInstancesManagerWidget->save();
    mConfigurePluginsWidget->save();
    mConfigureFontWidget->save();
    mConfigureSpellCheckingWidget->save();
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->save();
#endif
#if HAVE_KUSERFEEDBACK
    mConfigureUserFeedBackWidget->save();
#endif
}

void KAIChatConfigureSettingsDialog::load()
{
    mConfigureGeneralWidget->load();
    mConfigurePluginsWidget->load();
    mConfigureFontWidget->load();
    mConfigureSpellCheckingWidget->load();
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->load();
#endif
#if HAVE_KUSERFEEDBACK
    mConfigureUserFeedBackWidget->load();
#endif
}

void KAIChatConfigureSettingsDialog::slotRestoreDefaults()
{
    if (currentPage() == mConfigureGeneralWidgetPage) {
        mConfigureGeneralWidget->restoreToDefaults();
    } else if (currentPage() == mConfigureFontWidgetPage) {
        mConfigureFontWidget->restoreToDefaults();
    } else if (currentPage() == mConfigureInstancesWidgetPage) {
        mInstancesManagerWidget->restoreToDefaults();
    } else if (currentPage() == mConfigureSpellCheckWidgetPage) {
        mConfigureSpellCheckingWidget->restoreToDefaults();
#if HAVE_TEXT_TO_SPEECH
    } else if (currentPage() == mConfigureTextToSpeechWidgetPage) {
        mConfigureAccessibilityWidget->restoreToDefaults();
#endif
#if HAVE_KUSERFEEDBACK
    } else if (currentPage() == mConfigureUserFeedBackWidgetPage) {
        mConfigureUserFeedBackWidget->restoreToDefaults();
#endif
    } else if (currentPage() == mConfigurePluginsWidgetPage) {
        // Necessary ? mConfigurePluginsWidget->restoreToDefaults();
    } else {
        qCWarning(KAICHAT_WIDGET_LOG) << " slotRestoreDefault not implemented for current page";
    }
}

#include "moc_kaichatconfiguresettingsdialog.cpp"
