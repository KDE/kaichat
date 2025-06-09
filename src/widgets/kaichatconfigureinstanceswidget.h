/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QWidget>

class KAIChatConfigureInstancesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureInstancesWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureInstancesWidget() override;
    void save();
    void load();
};
