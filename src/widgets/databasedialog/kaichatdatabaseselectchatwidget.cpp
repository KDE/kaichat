/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatwidget.h"
#include "databasedialog/kaichatdatabasemessageslistview.h"
#include "databasedialog/kaichatdatabaseselectchatlineedit.h"
#include <QVBoxLayout>
#include <textautogeneratetext/textautogeneratelocaldatabasemanager.h>
#include <textautogeneratetext/textautogeneratelocalmessagesdatabase.h>
#include <textautogeneratetext/textautogeneratemanager.h>

using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseSelectChatWidget::KAIChatDatabaseSelectChatWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mMessagesListView(new KAIChatDatabaseMessagesListView(manager, this))
    , mLineEdit(new KAIChatDatabaseSelectChatLineEdit(this))
    , mManager(manager)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mLineEdit->setObjectName(u"mLineEdit"_s);
    mainLayout->addWidget(mLineEdit);

    mMessagesListView->setObjectName(u"mMessagesListView"_s);
    mainLayout->addWidget(mMessagesListView);

    connect(mLineEdit, &KAIChatDatabaseSelectChatLineEdit::selectChatId, this, &KAIChatDatabaseSelectChatWidget::selectChatId);
}

KAIChatDatabaseSelectChatWidget::~KAIChatDatabaseSelectChatWidget() = default;

void KAIChatDatabaseSelectChatWidget::loadMessages(const QString &chatId)
{
    if (mManager) {
        const auto messages = mManager->databaseManager()->messagesDatabase()->loadMessages(chatId);
        Q_UNUSED(messages);
        // TODO
        // mMessagesListView->model()->
    }
}

#include "moc_kaichatdatabaseselectchatwidget.cpp"
