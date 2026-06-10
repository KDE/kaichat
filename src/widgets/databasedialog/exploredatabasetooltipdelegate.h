/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QStyledItemDelegate>

class LIBKAICHATWIDGETS_TESTS_EXPORT ExploreDatabaseTooltipDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ExploreDatabaseTooltipDelegate(QObject *parent = nullptr);
    ~ExploreDatabaseTooltipDelegate() override;

    [[nodiscard]] bool helpEvent(QHelpEvent *event, QAbstractItemView *view, const QStyleOptionViewItem &option, const QModelIndex &index) override;
};
