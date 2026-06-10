/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <TextAutoGenerateText/TextAutoGenerateBaseListView>

class KAIChatDatabaseMessagesListView : public TextAutoGenerateText::TextAutoGenerateBaseListView
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseMessagesListView(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseMessagesListView() override;

protected:
    [[nodiscard]] QString originalMessage(const QModelIndex &index) const override;
};
