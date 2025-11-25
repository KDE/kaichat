/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcommandlineparsertest.h"
#include "kaichatcommandlineparser.h"
#include <QTest>
QTEST_GUILESS_MAIN(KAIChatCommandLineParserTest)
using namespace Qt::Literals::StringLiterals;
KAIChatCommandLineParserTest::KAIChatCommandLineParserTest(QObject *parent)
    : QObject{parent}
{
}

void KAIChatCommandLineParserTest::shouldVerifyOptionParserFromEnumValues()
{
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::ListInstances), u"list-instances"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::Instance), u"instance"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::NewChat), u"new-chat"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::QuickAsk), u"quick-ask"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SwitchToChat), u"switch-to-chat"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::AskMessage), u"ask-message"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::ListChats), u"list-chats"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SwitchToChatFromId), u"switch-to-chat-from-id"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::Debug), u"debug"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::Attach), u"attach"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::ToolName), u"tool"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::PluginInfo), u"plugin-info"_s);
}

#include "moc_kaichatcommandlineparsertest.cpp"
