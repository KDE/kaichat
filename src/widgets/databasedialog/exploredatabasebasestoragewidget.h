/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QSqlTableModel>
#include <QWidget>
#include <memory>
class QTableView;
class JsonPlainTextEditWidget;
class QLineEdit;
class QSortFilterProxyModel;
class LIBKAICHATWIDGETS_TESTS_EXPORT ExploreDatabaseBaseStorageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ExploreDatabaseBaseStorageWidget(QWidget *parent = nullptr);
    ~ExploreDatabaseBaseStorageWidget() override;

protected:
    void setModel(QAbstractItemModel *model);

    std::unique_ptr<QSqlTableModel> mModel;
    QTableView *const mTableView;
    JsonPlainTextEditWidget *const mTextEdit;
    QLineEdit *const mFilterLineEdit;
    QSortFilterProxyModel *const mSortFilterProxyModel;

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotCellClicked(const QModelIndex &index);
};
