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
                                         i18n("Instance Name")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::NewChat), i18nc("@info:shell", "Create new chat"), i18n("New Chat Title")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::QuickAsk), i18nc("@info:shell", "Open Quick Ask")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::SwitchToChat), i18nc("@info:shell", "Switch to Chat"), i18n("Chat Name")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::SwitchToChatFromId),
                                         i18nc("@info:shell", "Switch to Chat from identifier"),
                                         i18n("Chat Identifier")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::AskMessage), i18nc("@info:shell", "Ask Message"), i18n("Message")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::ListChats), i18nc("@info:shell", "Return lists of chats")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::Debug), i18nc("@info:shell", "Activate Debug Mode")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::Attach),
                                         i18nc("@info:shell", "Add an attachment. This can be repeated"),
                                         i18n("Attachment Url")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::ToolName),
                                         i18nc("@info:shell", "Define tool used. This can be repeated"),
                                         i18n("Tool Name")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::PluginInfo), i18nc("@info:shell", "Return plugins info")));
#if HAVE_KUSERFEEDBACK
    parser->addOption(QCommandLineOption(optionParserFromEnum(OptionParser::FeedBack), i18nc("@info:shell", "Lists the available options for user feedback")));
#endif
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
    case OptionParser::SwitchToChatFromId:
        return u"switch-to-chat-from-id"_s;
    case OptionParser::AskMessage:
        return u"ask-message"_s;
    case OptionParser::ListChats:
        return u"list-chats"_s;
    case OptionParser::Debug:
        return u"debug"_s;
    case OptionParser::Attach:
        return u"attach"_s;
    case OptionParser::ToolName:
        return u"tool"_s;
#if HAVE_KUSERFEEDBACK
    case OptionParser::FeedBack:
        return u"feedback"_s;
#endif
    case OptionParser::PluginInfo:
        return u"plugin-info"_s;
    }
    return {};
}
