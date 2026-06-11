/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QWidget>
class KAIChatDatabaseMessagesListView;
class KAIChatDatabaseSelectChatLineEdit;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class KAIChatDatabaseSelectChatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseSelectChatWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseSelectChatWidget() override;

private:
    KAIChatDatabaseMessagesListView *const mMessagesListView;
    KAIChatDatabaseSelectChatLineEdit *const mLineEdit;
};
