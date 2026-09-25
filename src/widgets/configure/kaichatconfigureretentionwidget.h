/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>
class QCheckBox;
class QSpinBox;
class KAIChatConfigureRetentionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureRetentionWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureRetentionWidget() override;
    void save();
    void load();
    void restoreToDefaults();
};
