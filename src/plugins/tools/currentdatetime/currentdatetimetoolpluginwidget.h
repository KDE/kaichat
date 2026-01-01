/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QWidget>
namespace TextAutoGenerateText
{
class TextAutoGenerateToolPluginConfigureWidget;
class TextAutoGenerateTextToolPlugin;
}
class CurrentDateTimeToolPluginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CurrentDateTimeToolPluginWidget(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent = nullptr);
    ~CurrentDateTimeToolPluginWidget() override;

private:
    TextAutoGenerateText::TextAutoGenerateToolPluginConfigureWidget *const mConfigureWidget;
};
