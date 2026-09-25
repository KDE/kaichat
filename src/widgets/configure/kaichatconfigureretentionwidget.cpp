/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureretentionwidget.h"
#include "textautogeneratetext/textautogeneratetextglobalconfig.h"
#include <KLocalizedString>
#include <QCheckBox>
#include <QFormLayout>
#include <QSpinBox>
using namespace Qt::Literals::StringLiterals;
KAIChatConfigureRetentionWidget::KAIChatConfigureRetentionWidget(QWidget *parent)
    : QWidget{parent}
    , mExcludeFavoriteChats(new QCheckBox(i18n("Exclude Favorite Chats"), this))
    , mHistoryRetentionDays(new QSpinBox(this))
{
    auto mainLayout = new QFormLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});
    mExcludeFavoriteChats->setObjectName(u"mExcludeFavoriteChats"_s);
    mHistoryRetentionDays->setObjectName(u"mHistoryRetentionDays"_s);
    mainLayout->addWidget(mExcludeFavoriteChats);
    mainLayout->addRow(i18n("Retention Days"), mHistoryRetentionDays);
}

KAIChatConfigureRetentionWidget::~KAIChatConfigureRetentionWidget() = default;

void KAIChatConfigureRetentionWidget::save()
{
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setExcludeFavoriteChat(mExcludeFavoriteChats->isChecked());
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setHistoryRetentionDays(mHistoryRetentionDays->value());
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->save();
}

void KAIChatConfigureRetentionWidget::load()
{
    mExcludeFavoriteChats->setChecked(TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->excludeFavoriteChat());
    mHistoryRetentionDays->setValue(TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->historyRetentionDays());
}

void KAIChatConfigureRetentionWidget::restoreToDefaults()
{
    const bool bUseDefaults = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(true);
    load();
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(bUseDefaults);
}

#include "moc_kaichatconfigureretentionwidget.cpp"
