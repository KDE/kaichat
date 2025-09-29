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
class ExampleTextToolPluginWidget;
class ExampleTextToolPluginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ExampleTextToolPluginDialog(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent = nullptr);
    ~ExampleTextToolPluginDialog() override;

private:
    ExampleTextToolPluginWidget *const mExampleTextToolPluginWidget;
};
