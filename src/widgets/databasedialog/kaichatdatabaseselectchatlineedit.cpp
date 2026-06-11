/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatlineedit.h"

KAIChatDatabaseSelectChatLineEdit::KAIChatDatabaseSelectChatLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setClearButtonEnabled(true);
}

KAIChatDatabaseSelectChatLineEdit::~KAIChatDatabaseSelectChatLineEdit() = default;
#include "moc_kaichatdatabaseselectchatlineedit.cpp"
