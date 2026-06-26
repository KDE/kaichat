/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatwidgets_private_export.h"
#include <TextAddonsWidgets/CompletionLineEdit>
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
class TextAutoGenerateChat;
}
class KAIChatCompletionListModel;
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatDatabaseSelectChatLineEdit : public TextAddonsWidgets::CompletionLineEdit
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseSelectChatLineEdit(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseSelectChatLineEdit() override;

Q_SIGNALS:
    void selectChatId(const QByteArray &chatId);

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotComplete(const QModelIndex &index);
    LIBKAICHATWIDGETS_NO_EXPORT void slotSearchTextEdited(const QString &str);
    QList<TextAutoGenerateText::TextAutoGenerateChat> mChats;
    KAIChatCompletionListModel *const mCompletionListModel;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
};
