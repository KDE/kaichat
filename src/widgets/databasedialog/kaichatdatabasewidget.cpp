/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasewidget.h"
#include "databasedialog/kaichatdatabasechatwidget.h"
#include <KLocalizedString>
#include <QTabWidget>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseWidget::KAIChatDatabaseWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mTabWidget(new QTabWidget(this))
    , mDatabaseChatWidget(new KAIChatDatabaseChatWidget(manager, this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);

    mTabWidget->setObjectName("mTabWidget"_L1);
    mainLayout->addWidget(mTabWidget);

    mDatabaseChatWidget->setObjectName("mDatabaseChatWidget"_L1);
    mTabWidget->addTab(mDatabaseChatWidget, i18n("Chat"));
}

KAIChatDatabaseWidget::~KAIChatDatabaseWidget() = default;

#include "moc_kaichatdatabasewidget.cpp"
