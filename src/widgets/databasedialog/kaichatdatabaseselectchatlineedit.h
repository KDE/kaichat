/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QLineEdit>

class KAIChatDatabaseSelectChatLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseSelectChatLineEdit(QWidget *parent = nullptr);
    ~KAIChatDatabaseSelectChatLineEdit() override;
};
