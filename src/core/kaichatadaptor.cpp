/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatadaptor.h"
#include <QApplication>

KAIChatAdaptor::KAIChatAdaptor(TextAutoGenerateText::TextAutoGenerateManager *manager, QObject *parent)
    : QDBusAbstractAdaptor(parent)
    , mManager(manager)
{
}

KAIChatAdaptor::~KAIChatAdaptor() = default;

QStringList KAIChatAdaptor::chatsList()
{
    return mManager->chatsList();
}

void KAIChatAdaptor::switchToChat(const QString &chatName)
{
    mManager->switchToChat(chatName);
}

void KAIChatAdaptor::switchToChatId(const QByteArray &chatId)
{
    mManager->switchToChatId(chatId);
}

void KAIChatAdaptor::showArchived(bool b)
{
    mManager->setShowArchived(b);
}

void KAIChatAdaptor::createNewChat(const QString &title)
{
    mManager->createNewChat(title);
}

void KAIChatAdaptor::ask(const QString &message)
{
    const TextAutoGenerateText::TextAutoGenerateManager::AskMessageInfo info{
        .message = message,
        .attachments = {},
        .tools = {},
    };
    mManager->ask(info);
}

#include "moc_kaichatadaptor.cpp"
