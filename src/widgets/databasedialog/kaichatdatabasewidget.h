/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include <QWidget>
class QTabWidget;
class KAIChatDatabaseChatWidget;
class KAIChatDatabaseMessagesWidget;
class KAIChatDatabaseMessageJsonWidget;
class KAIChatDatabaseChatPendingTypedInfoWidget;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class KAIChatDatabaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseWidget() override;

private:
    QTabWidget *const mTabWidget;
    KAIChatDatabaseChatWidget *const mDatabaseChatWidget;
    KAIChatDatabaseChatPendingTypedInfoWidget *const mDatabaseChatPendingTypedInfoWidget;
    KAIChatDatabaseMessagesWidget *const mDatabaseMessagesWidget;
    KAIChatDatabaseMessageJsonWidget *const mDatabaseMessageJsonWidget;
};
