/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>
class QCheckBox;
class KFontChooser;
class KAIChatConfigureFontWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureFontWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureFontWidget() override;
    void save();
    void load();
    void restoreToDefaults();

private:
    QCheckBox *const mCustomFontCheck;
    KFontChooser *const mFontChooser;
};
