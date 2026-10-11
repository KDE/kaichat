/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>
#include <textautogeneratetext_version.h>
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
namespace TextAutoGenerateText
{
class TextAutoGenerateTextConfigureMcpServersWidget;
}
#else
namespace TextAutoGenerateTextMcpProtocolWidgets
{
class McpServerWidget;
}
#endif
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class KAIChatConfigureMcpServersWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureMcpServersWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatConfigureMcpServersWidget() override;

    void save();
    void load();
    void restoreToDefaults();

private:
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
    TextAutoGenerateText::TextAutoGenerateTextConfigureMcpServersWidget *const mConfigureMcpServersWidget;
#else
    TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget *const mMcpServerWidget;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
#endif
};
