/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QTabWidget>

class KAIChatConfigureAccessibilityTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureAccessibilityTabWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureAccessibilityTabWidget() override;

    void save();
    void load();
    void restoreToDefaults();
};
