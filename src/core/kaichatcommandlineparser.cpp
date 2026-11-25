/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcommandlineparser.h"
#include "kaichat_core_debug.h"
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
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::NewChat), i18nc("@info:shell", "Create new chat"), i18n("New Chat Title")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::EphemeralChat),
                                         i18nc("@info:shell", "Create new ephemeral chat"),
                                         i18n("New Ephemeral Chat")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::QuickAsk), i18nc("@info:shell", "Open Quick Ask")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::SwitchToChat), i18nc("@info:shell", "Switch to Chat"), i18n("Chat Name")));
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::SwitchToChatFromId),
                                         i18nc("@info:shell", "Switch to Chat from identifier"),
                                         i18n("Chat Identifier")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::AskMessage), i18nc("@info:shell", "Ask Message"), i18n("Message")));

    QCommandLineOption promptOption(QStringList() << optionParserFromEnum(OptionParser::Prompt),
                                    i18nc("@info:shell", "Ask a predefined question (summarize, explain-code). Ignored when a message is given"),
                                    i18n("Prompt Name"));
    promptOption.setFlags(QCommandLineOption::HiddenFromHelp);

    parser->addOption(promptOption);
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
    parser->addOption(QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::ImportChat), i18nc("@info:shell", "Import Chat"), i18n("Import")));
    parser->addOption(
        QCommandLineOption(QStringList() << optionParserFromEnum(OptionParser::StartOllamaProgram), i18nc("@info:shell", "Start Ollama program")));
    QCommandLineOption selfTestOption(optionParserFromEnum(OptionParser::SelfTest), QStringLiteral("internal, for automated testing"));
    selfTestOption.setFlags(QCommandLineOption::HiddenFromHelp);
    parser->addOption(selfTestOption);
    parser->addPositionalArgument(u"file"_s, i18nc("@info:shell", "Chat file to import"), u"[file…]"_s);
}

QString KAIChatCommandLineParser::optionParserFromEnum(OptionParser e)
{
    switch (e) {
    case OptionParser::ListInstances:
        return u"list-instances"_s;
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
    case OptionParser::ImportChat:
        return u"import"_s;
    case OptionParser::StartOllamaProgram:
        return u"start-ollama"_s;
    case OptionParser::SelfTest:
        return u"self-test"_s;
    case OptionParser::EphemeralChat:
        return u"ephemeral-chat"_s;
    case OptionParser::Prompt:
        return u"prompt"_s;
    }
    return {};
}

QString KAIChatCommandLineParser::promptMessage(const QString &promptName)
{
    if (promptName == "summarize"_L1) {
        return i18nc("@info Question sent to the AI model", "Summarize this document.");
    } else if (promptName == "explain-code"_L1) {
        return i18nc("@info Question sent to the AI model", "Explain what this code does.");
    }
    return {};
}

TextAutoGenerateText::TextAutoGenerateManager::AskMessageInfo KAIChatCommandLineParser::askMessageInfo(const QCommandLineParser *parser)
{
    QString message;
    if (parser->isSet(optionParserFromEnum(OptionParser::AskMessage))) {
        message = parser->value(optionParserFromEnum(OptionParser::AskMessage));
    }
    if (message.isEmpty() && parser->isSet(optionParserFromEnum(OptionParser::Prompt))) {
        const QString promptName = parser->value(optionParserFromEnum(OptionParser::Prompt));
        message = promptMessage(promptName);
        if (message.isEmpty()) {
            qCWarning(KAICHAT_CORE_LOG) << "Unknown prompt name:" << promptName;
        }
    }
    QStringList lstAttachments;
    if (parser->isSet(optionParserFromEnum(OptionParser::Attach))) {
        lstAttachments = parser->values(optionParserFromEnum(OptionParser::Attach));
    }
    QList<QByteArray> tools;
    if (parser->isSet(optionParserFromEnum(OptionParser::ToolName))) {
        const QStringList toolNames = parser->values(optionParserFromEnum(OptionParser::ToolName));
        tools.reserve(toolNames.size());
        for (const auto &t : toolNames) {
            tools.append(t.toLatin1());
        }
    }
    return {.message = std::move(message), .attachments = std::move(lstAttachments), .tools = std::move(tools)};
}
