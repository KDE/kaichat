/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasemessageslistview.h"
#include <TextAutoGenerateText/TextAutoGenerateListViewDelegate>
#include <TextAutoGenerateText/TextAutoGenerateMessagesModel>

KAIChatDatabaseMessagesListView::KAIChatDatabaseMessagesListView(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : TextAutoGenerateText::TextAutoGenerateBaseListView(manager, parent)
    , mCurrentModel(new TextAutoGenerateText::TextAutoGenerateMessagesModel(this))
{
    setModel(mCurrentModel);
    auto delegate = new TextAutoGenerateText::TextAutoGenerateListViewDelegate(manager, this);
    mDelegate = delegate;
    setItemDelegate(mDelegate);
}

KAIChatDatabaseMessagesListView::~KAIChatDatabaseMessagesListView() = default;

void KAIChatDatabaseMessagesListView::setMessages(const QList<TextAutoGenerateText::TextAutoGenerateMessage> &newMessages)
{
    mCurrentModel->setMessages(newMessages);
}

QString KAIChatDatabaseMessagesListView::originalMessage([[maybe_unused]] const QModelIndex &index) const
{
    // TODO
    return {};
}

#include "moc_kaichatdatabasemessageslistview.cpp"
