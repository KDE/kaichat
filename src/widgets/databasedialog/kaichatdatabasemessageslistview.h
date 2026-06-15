/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <TextAutoGenerateText/TextAutoGenerateBaseListView>
namespace TextAutoGenerateText
{
class TextAutoGenerateMessagesModel;
class TextAutoGenerateMessage;
}
class KAIChatDatabaseMessagesListView : public TextAutoGenerateText::TextAutoGenerateBaseListView
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseMessagesListView(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseMessagesListView() override;

    void setMessages(const QList<TextAutoGenerateText::TextAutoGenerateMessage> &newMessages);

protected:
    [[nodiscard]] QString originalMessage(const QModelIndex &index) const override;

private:
    TextAutoGenerateText::TextAutoGenerateMessagesModel *const mCurrentModel;
};
