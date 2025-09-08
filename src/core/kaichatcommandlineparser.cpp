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
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::Instance),
                                         i18nc("@info:shell", "Start with specific instance"),
                                         u"instancename"_s));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::NewChat), i18nc("@info:shell", "Create new chat"), u"New Chat"_s));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::QuickAsk), i18nc("@info:shell", "Open Quick Ask")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::SwitchToChat), i18nc("@info:shell", "Switch to Chat"), u"Chat Name"_s));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::AskMessage), i18nc("@info:shell", "Ask Message"), u"Message"_s));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::ListChats), i18nc("@info:shell", "Return lists of chats")));
}

QString KAIChatCommandLineParser::optionParserFromEnum(OptionParser e)
{
    switch (e) {
    case OptionParser::ListInstances:
        return u"list-instances"_s;
    case OptionParser::Instance:
        return u"instance"_s;
    case OptionParser::NewChat:
        return u"new-chat"_s;
    case OptionParser::QuickAsk:
        return u"quick-ask"_s;
    case OptionParser::SwitchToChat:
        return u"switch-to-chat"_s;
    case OptionParser::AskMessage:
        return u"ask-message"_s;
    case OptionParser::ListChats:
        return u"list-chats"_s;
    }
    return {};
}
