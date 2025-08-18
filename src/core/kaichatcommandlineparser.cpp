/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcommandlineparser.h"
#include <KLocalizedString>
#include <QCommandLineParser>

using namespace Qt::Literals::StringLiterals;
KAIChatCommandLineParser::KAIChatCommandLineParser(QCommandLineParser *parser)
{
    initializeCommandLine(parser);
}

KAIChatCommandLineParser::~KAIChatCommandLineParser() = default;

void KAIChatCommandLineParser::initializeCommandLine(QCommandLineParser *parser)
{
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::ListInstances), i18nc("@info:shell", "Return lists of instances")));
}

QString KAIChatCommandLineParser::optionParserFromEnum(OptionParser e)
{
    switch (e) {
    case OptionParser::ListInstances:
        return u"list-instances"_s;
    }
    return {};
}
