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

KAIChatConfigureGeneralWidget::KAIChatConfigureGeneralWidget(QWidget *parent)
    : QWidget{parent}
    , mEnableSystemTray(new QCheckBox(i18nc("@option:check", "Enable system tray icon"), this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(QStringLiteral("mainLayout"));
    mEnableSystemTray->setObjectName(QStringLiteral("mEnableSystemTray"));
    mainLayout->addWidget(mEnableSystemTray);
    mainLayout->addStretch(1);
}

KAIChatConfigureGeneralWidget::~KAIChatConfigureGeneralWidget() = default;

void KAIChatConfigureGeneralWidget::save()
{
    KAIChatGlobalConfig::self()->setEnableSystemTray(mEnableSystemTray->isChecked());
}

void KAIChatConfigureGeneralWidget::load()
{
    mEnableSystemTray->setChecked(KAIChatGlobalConfig::self()->enableSystemTray());
}

#include "moc_kaichatconfiguregeneralwidget.cpp"
