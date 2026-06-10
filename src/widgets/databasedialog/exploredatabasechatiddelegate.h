/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once
#include "libkaichatwidgets_private_export.h"
#include <QStyledItemDelegate>
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class LIBKAICHATWIDGETS_TESTS_EXPORT ExploreDatabaseChatIdDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ExploreDatabaseChatIdDelegate(TextAutoGenerateText::TextAutoGenerateManager *manager, QObject *parent = nullptr);
    ~ExploreDatabaseChatIdDelegate() override;

    [[nodiscard]] QString displayText(const QVariant &value, const QLocale &locale) const override;

    [[nodiscard]] bool helpEvent(QHelpEvent *event, QAbstractItemView *view, const QStyleOptionViewItem &option, const QModelIndex &index) override;

private:
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
};
