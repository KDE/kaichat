/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatconfiguresettingsdialog.h"
using namespace Qt::Literals::StringLiterals;

#include "kaichatconfiguregeneralwidget.h"
#include "kaichatconfigureinstanceswidget.h"
#include <KLocalizedString>
#include <KSharedConfig>
#include <KWindowConfig>
#include <QPushButton>
#include <QWindow>
#include <TextAutoGenerateText/TextAutoGenerateTextConfigurePluginsWidget>
namespace
{
const char myConfigGroupName[] = "KAIChatConfigureSettingsDialog";
}
KAIChatConfigureSettingsDialog::KAIChatConfigureSettingsDialog(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : KPageDialog(parent)
    , mConfigureGeneralWidget(new KAIChatConfigureGeneralWidget(manager, this))
    , mInstancesManagerWidget(new KAIChatConfigureInstancesWidget(manager, this))
    , mConfigurePluginsWidget(new TextAutoGenerateText::TextAutoGenerateTextConfigurePluginsWidget(this))
{
    setWindowTitle(i18nc("@title:window", "Configure KAIChat"));
    setFaceType(KPageDialog::List);

    const QString generalPageName = i18nc("@title General page name", "General");
    auto configureGeneralWidgetPage = new KPageWidgetItem(mConfigureGeneralWidget, generalPageName);
    addPage(configureGeneralWidgetPage);

    const QString instancesPageName = i18nc("@title Instances page name", "Instances");
    auto configureInstancesWidgetPage = new KPageWidgetItem(mInstancesManagerWidget, instancesPageName);
    addPage(configureInstancesWidgetPage);

    const QString pluginsPageName = i18nc("@title Instances page name", "Plugins");
    auto configurePluginsWidgetPage = new KPageWidgetItem(mConfigurePluginsWidget, pluginsPageName);
    addPage(configurePluginsWidgetPage);

    buttonBox()->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox()->button(QDialogButtonBox::Ok), &QPushButton::clicked, this, &KAIChatConfigureSettingsDialog::slotAccepted);
    connect(buttonBox()->button(QDialogButtonBox::Cancel), &QPushButton::clicked, this, &KAIChatConfigureSettingsDialog::reject);
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
}

void KAIChatConfigureSettingsDialog::load()
{
    mConfigureGeneralWidget->load();
    mConfigurePluginsWidget->load();
}

#include "moc_kaichatconfiguresettingsdialog.cpp"
