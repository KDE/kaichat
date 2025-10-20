/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatconfiguregeneralwidget.h"

#include "kaichatglobalconfig.h"
#include <KLocalizedString>
#include <QCheckBox>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateTextConfigurePromptWidget>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureGeneralWidget::KAIChatConfigureGeneralWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mEnableSystemTray(new QCheckBox(i18nc("@option:check", "Enable system tray icon"), this))
    , mConfigurePromptWidget(new TextAutoGenerateText::TextAutoGenerateTextConfigurePromptWidget(this))
    , mManager(manager)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mEnableSystemTray->setObjectName(u"mEnableSystemTray"_s);
    mainLayout->addWidget(mEnableSystemTray);

    mConfigurePromptWidget->setObjectName(u"mConfigurePromptWidget"_s);
    mainLayout->addWidget(mConfigurePromptWidget);

    mainLayout->addStretch(1);
}

KAIChatConfigureGeneralWidget::~KAIChatConfigureGeneralWidget() = default;

void KAIChatConfigureGeneralWidget::save()
{
    KAIChatGlobalConfig::self()->setEnableSystemTray(mEnableSystemTray->isChecked());
    mManager->setSystemPrompt(mConfigurePromptWidget->systemPrompt());
}

void KAIChatConfigureGeneralWidget::load()
{
    mEnableSystemTray->setChecked(KAIChatGlobalConfig::self()->enableSystemTray());
    mConfigurePromptWidget->setSystemPrompt(mManager->systemPrompt());
}

void KAIChatConfigureGeneralWidget::restoreToDefaults()
{
    // TODO
}

#include "moc_kaichatconfiguregeneralwidget.cpp"
