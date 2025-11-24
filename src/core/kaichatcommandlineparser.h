/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"

#include <QString>
class QCommandLineParser;
class LIBKAICHATCORE_EXPORT KAIChatCommandLineParser
{
public:
    enum class OptionParser : uint8_t {
        ListInstances = 0,
        Instance,
        NewChat,
        QuickAsk,
        SwitchToChat,
        SwitchToChatFromId,
        AskMessage,
        ListChats,
        Debug,
        Attach,
        ToolName,
    };
    explicit KAIChatCommandLineParser(QCommandLineParser *parser);
    ~KAIChatCommandLineParser();

    [[nodiscard]] static QString optionParserFromEnum(OptionParser e);

private:
    LIBKAICHATCORE_NO_EXPORT void initializeCommandLine(QCommandLineParser *parser);
};
