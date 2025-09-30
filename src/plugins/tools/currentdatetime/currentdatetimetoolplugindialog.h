/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QDialog>
namespace TextAutoGenerateText
{
class TextAutoGenerateTextToolPlugin;
}
class CurrentDateTimeToolPluginWidget;
class CurrentDateTimeToolPluginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CurrentDateTimeToolPluginDialog(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent = nullptr);
    ~CurrentDateTimeToolPluginDialog() override;

private:
    CurrentDateTimeToolPluginWidget *const mCurrentDateTimeToolPluginWidget;
};
