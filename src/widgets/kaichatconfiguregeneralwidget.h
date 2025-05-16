/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include <QWidget>

class KAIChatConfigureGeneralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureGeneralWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureGeneralWidget() override;
};
