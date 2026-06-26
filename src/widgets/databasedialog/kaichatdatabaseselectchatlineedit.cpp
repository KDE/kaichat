/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatlineedit.h"
#include "kaichatcompletionlistmodel.h"
#include <KLocalizedString>
#include <TextAddonsWidgets/CompletionListView>
#include <TextAutoGenerateText/TextAutoGenerateChatsModel>
#include <TextAutoGenerateText/TextAutoGenerateManager>

using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseSelectChatLineEdit::KAIChatDatabaseSelectChatLineEdit(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : TextAddonsWidgets::CompletionLineEdit(parent)
    , mCompletionListModel(new KAIChatCompletionListModel(this))
    , mManager(manager)
{
    setClearButtonEnabled(true);
    setPlaceholderText(i18nc("@info:placeholder", "Select Chat Name"));

    if (manager) {
        mChats = mManager->textAutoGenerateChatsModel()->chats();
        setCompletionModel(mCompletionListModel);
    }
    connect(this, &KAIChatDatabaseSelectChatLineEdit::complete, this, &KAIChatDatabaseSelectChatLineEdit::slotComplete);
    connect(this, &QLineEdit::textChanged, this, &KAIChatDatabaseSelectChatLineEdit::slotSearchTextEdited);
    mCompletionListView->setTextWidget(this);
}

KAIChatDatabaseSelectChatLineEdit::~KAIChatDatabaseSelectChatLineEdit() = default;

void KAIChatDatabaseSelectChatLineEdit::slotSearchTextEdited(const QString &str)
{
    QList<KAIChatCompletionListModel::CompletionInfo> lstInfos;
    for (const auto &c : std::as_const(mChats)) {
        if (c.title().contains(str)) {
            lstInfos.append({
                .chatName = c.title(),
                .chatId = c.identifier(),
            });
        }
    }
    mCompletionListModel->setCompletionInfos(lstInfos);
    if (lstInfos.isEmpty()) {
        mCompletionListView->hide();
    }
}

void KAIChatDatabaseSelectChatLineEdit::slotComplete([[maybe_unused]] const QModelIndex &index)
{
    const QString completerName = index.data(KAIChatCompletionListModel::ChatName).toString();
    const QByteArray roomId = index.data(KAIChatCompletionListModel::ChatUuid).toByteArray();
    if (completerName.isEmpty() || roomId.isEmpty()) {
        return;
    }
    mCompletionListView->hide();
    Q_EMIT selectChatId(roomId);
}

#include "moc_kaichatdatabaseselectchatlineedit.cpp"
