/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatwidget.h"
#include "databasedialog/kaichatdatabasemessageslistview.h"
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseSelectChatWidget::KAIChatDatabaseSelectChatWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mMessagesListView(new KAIChatDatabaseMessagesListView(manager, this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mMessagesListView->setObjectName(u"mMessagesListView"_s);
    mainLayout->addWidget(mMessagesListView);
}

KAIChatDatabaseSelectChatWidget::~KAIChatDatabaseSelectChatWidget() = default;

#include "moc_kaichatdatabaseselectchatwidget.cpp"
