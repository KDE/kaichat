/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once

#include <QWidget>
class JsonPlainTextEditWidget;
class KAIChatDatabaseMessageJsonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseMessageJsonWidget(QWidget *parent = nullptr);
    ~KAIChatDatabaseMessageJsonWidget() override;

    void setJson(const QString &json);

private:
    JsonPlainTextEditWidget *const mJsonPlainTextEditWidget;
};
