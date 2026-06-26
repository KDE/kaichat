/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatlineedit.h"
#include <KLocalizedString>

KAIChatDatabaseSelectChatLineEdit::KAIChatDatabaseSelectChatLineEdit(QWidget *parent)
    : TextAddonsWidgets::CompletionLineEdit(parent)
{
    setClearButtonEnabled(true);
    setPlaceholderText(i18nc("@info:placeholder", "Select Chat Name"));

    // TODO setCompletionModel(mJoinedChannelModel);
    connect(this, &KAIChatDatabaseSelectChatLineEdit::complete, this, &KAIChatDatabaseSelectChatLineEdit::slotComplete);
}

KAIChatDatabaseSelectChatLineEdit::~KAIChatDatabaseSelectChatLineEdit() = default;

void KAIChatDatabaseSelectChatLineEdit::slotComplete([[maybe_unused]] const QModelIndex &index)
{
    // TODO
#if 0
    const QString completerName = index.data(JoinedChannelModel::Name).toString();
    const QByteArray roomId = index.data(JoinedChannelModel::ChannelId).toByteArray();
    if (completerName.isEmpty() || roomId.isEmpty()) {
        return;
    }
    const JoinedChannelCompletionInfo info{
        .name = completerName,
        .channelId = roomId,
    };
    mCompletionListView->hide();
    Q_EMIT joinedChannelFound(std::move(info));
#endif
}

QByteArray KAIChatDatabaseSelectChatLineEdit::chatIdSelected() const
{
    return mChatIdSelected;
}

void KAIChatDatabaseSelectChatLineEdit::setChatIdSelected(const QByteArray &newChatIdSelected)
{
    mChatIdSelected = newChatIdSelected;
}

void KAIChatDatabaseSelectChatLineEdit::slotSelectChatId()
{
    if (!mChatIdSelected.isEmpty()) {
        Q_EMIT selectChatId(mChatIdSelected);
    }
}

#include "moc_kaichatdatabaseselectchatlineedit.cpp"
