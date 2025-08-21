/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>
namespace Sonnet
{
class ConfigWidget;
}
class KAIChatConfigureSpellCheckingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureSpellCheckingWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureSpellCheckingWidget() override;
    void save();
    void load();

private:
    Sonnet::ConfigWidget *const mConfigWidget;
};
