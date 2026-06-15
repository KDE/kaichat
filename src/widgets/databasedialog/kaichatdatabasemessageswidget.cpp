/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasemessageswidget.h"
#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateLocalMessagesDatabase>
#include <TextAutoGenerateText/TextAutoGenerateManager>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseMessagesWidget::KAIChatDatabaseMessagesWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
}

KAIChatDatabaseMessagesWidget::~KAIChatDatabaseMessagesWidget() = default;

void KAIChatDatabaseMessagesWidget::loadMessagesFromChatId(const QString &chatId)
{
    if (mManager) {
        mModel = mManager->databaseManager()->messagesDatabase()->createMessageModel(chatId);
        if (mModel) {
            setModel(mModel.get());
        } else {
            qCWarning(KAICHAT_WIDGET_LOG) << "Model is not defined from chatId: " << chatId;
        }
    }
}

#include "moc_kaichatdatabasemessageswidget.cpp"
