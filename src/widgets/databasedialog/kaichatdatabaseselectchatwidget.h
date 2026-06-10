/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QWidget>

class KAIChatDatabaseSelectChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseSelectChatWidget(QWidget *parent = nullptr);
    ~KAIChatDatabaseSelectChatWidget() override;
};
