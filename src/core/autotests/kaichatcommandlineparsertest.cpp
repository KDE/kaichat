/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcommandlineparsertest.h"
#include "config-kaichat.h"
#include "kaichatcommandlineparser.h"
#include <QCommandLineParser>
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
#if HAVE_KUSERFEEDBACK
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::FeedBack), u"feedback"_s);
#endif
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::ImportChat), u"import"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::StartOllamaProgram), u"start-ollama"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SelfTest), u"self-test"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::EphemeralChat), u"ephemeral-chat"_s);
    QCOMPARE(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::Prompt), u"prompt"_s);
}

void KAIChatCommandLineParserTest::shouldReturnPromptMessage()
{
    QVERIFY(!KAIChatCommandLineParser::promptMessage(u"summarize"_s).isEmpty());
    QVERIFY(!KAIChatCommandLineParser::promptMessage(u"explain-code"_s).isEmpty());
    QVERIFY(KAIChatCommandLineParser::promptMessage(u"unknown"_s).isEmpty());
    QVERIFY(KAIChatCommandLineParser::promptMessage({}).isEmpty());
}

void KAIChatCommandLineParserTest::shouldUsePromptInAskMessageInfo_data()
{
    QTest::addColumn<QStringList>("arguments");
    QTest::addColumn<QString>("message");
    QTest::addColumn<QStringList>("attachments");

    const QString summarize = KAIChatCommandLineParser::promptMessage(u"summarize"_s);
    QTest::newRow("attachment-only") << QStringList{u"--quick-ask"_s, u"--attach"_s, u"/tmp/a.txt"_s} << QString() << QStringList{u"/tmp/a.txt"_s};
    QTest::newRow("prompt") << QStringList{u"--quick-ask"_s, u"--attach"_s, u"/tmp/a.txt"_s, u"--prompt"_s, u"summarize"_s} << summarize
                            << QStringList{u"/tmp/a.txt"_s};
    QTest::newRow("message-wins") << QStringList{u"--ask-message"_s, u"Hello"_s, u"--prompt"_s, u"summarize"_s} << u"Hello"_s << QStringList();
    QTest::newRow("unknown-prompt") << QStringList{u"--attach"_s, u"/tmp/a.txt"_s, u"--prompt"_s, u"foo"_s} << QString() << QStringList{u"/tmp/a.txt"_s};
}

void KAIChatCommandLineParserTest::shouldUsePromptInAskMessageInfo()
{
    QFETCH(QStringList, arguments);
    QFETCH(QString, message);
    QFETCH(QStringList, attachments);

    QCommandLineParser parser;
    const KAIChatCommandLineParser commandLineParser(&parser);
    arguments.prepend(u"kaichat"_s);
    QVERIFY(parser.parse(arguments));

    const auto info = KAIChatCommandLineParser::askMessageInfo(&parser);
    QCOMPARE(info.message, message);
    QCOMPARE(info.attachments, attachments);
}

#include "moc_kaichatcommandlineparsertest.cpp"
