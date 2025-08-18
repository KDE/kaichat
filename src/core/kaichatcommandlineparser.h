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
    };
    explicit KAIChatCommandLineParser(QCommandLineParser *parser);
    ~KAIChatCommandLineParser();
    [[nodiscard]] QString optionParserFromEnum(OptionParser e);

private:
    void initializeCommandLine(QCommandLineParser *parser);
};
