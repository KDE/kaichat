/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatlineedit.h"
#include <KLocalizedString>

KAIChatDatabaseSelectChatLineEdit::KAIChatDatabaseSelectChatLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setClearButtonEnabled(true);
    setPlaceholderText(i18nc("@info:placeholder", "Select Chat Name"));
    connect(this, &QLineEdit::returnPressed, this, &KAIChatDatabaseSelectChatLineEdit::slotSelectChatId);
}

KAIChatDatabaseSelectChatLineEdit::~KAIChatDatabaseSelectChatLineEdit() = default;

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
