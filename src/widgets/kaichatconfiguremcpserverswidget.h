/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>

class KAIChatConfigureMcpServersWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureMcpServersWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureMcpServersWidget() override;

    void save();
    void load();
    void restoreToDefaults();
};
