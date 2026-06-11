/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatwidgets_private_export.h"
#include <QLineEdit>

class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatDatabaseSelectChatLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseSelectChatLineEdit(QWidget *parent = nullptr);
    ~KAIChatDatabaseSelectChatLineEdit() override;

Q_SIGNALS:
    void selectChatId(const QByteArray &chatId);
};
