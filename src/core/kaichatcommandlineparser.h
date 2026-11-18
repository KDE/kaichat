/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "config-kaichat.h"
#include "libkaichatcore_export.h"
#include <QString>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <cstdint>
class QCommandLineParser;
class LIBKAICHATCORE_EXPORT KAIChatCommandLineParser
{
public:
    enum class OptionParser : uint8_t {
        ListInstances = 0,
        NewChat,
        QuickAsk,
        SwitchToChat,
        SwitchToChatFromId,
        AskMessage,
        ListChats,
        Debug,
        Attach,
        ToolName,
        PluginInfo,
#if HAVE_KUSERFEEDBACK
        FeedBack,
#endif
        ImportChat,
        StartOllamaProgram,
        SelfTest,
        EphemeralChat,
    };
    explicit KAIChatCommandLineParser(QCommandLineParser *parser);
    ~KAIChatCommandLineParser();

    [[nodiscard]] static QString optionParserFromEnum(OptionParser e);
    [[nodiscard]] static TextAutoGenerateText::TextAutoGenerateManager::AskMessageInfo askMessageInfo(const QCommandLineParser *parser);

private:
    LIBKAICHATCORE_NO_EXPORT void initializeCommandLine(QCommandLineParser *parser);
};
