/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "kaichatdatabasemessagejsonwidget.h"
#include "databasedialog/jsonplaintexteditwidget.h"
#include <QVBoxLayout>
#include <textautogeneratetext/textautogeneratelocaldatabasemanager.h>
#include <textautogeneratetext/textautogeneratelocalmessagesdatabase.h>
#include <textautogeneratetext/textautogeneratemanager.h>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseMessageJsonWidget::KAIChatDatabaseMessageJsonWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mJsonPlainTextEditWidget(new JsonPlainTextEditWidget(this))
    , mManager(manager)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mJsonPlainTextEditWidget->setObjectName(u"mJsonPlainTextEditWidget"_s);
    mainLayout->addWidget(mJsonPlainTextEditWidget);
}

KAIChatDatabaseMessageJsonWidget::~KAIChatDatabaseMessageJsonWidget() = default;

void KAIChatDatabaseMessageJsonWidget::setJson(const QByteArray &chatId)
{
    if (mManager) {
        const auto messages = mManager->databaseManager()->messagesDatabase()->loadMessages(QString::fromLatin1(chatId));
        QByteArray str;
        for (const auto &m : messages) {
            str += TextAutoGenerateText::TextAutoGenerateMessage::serialize(m, false);
        }
        mJsonPlainTextEditWidget->setPlainText(QString::fromLatin1(str));
    }
}

#include "moc_kaichatdatabasemessagejsonwidget.cpp"
