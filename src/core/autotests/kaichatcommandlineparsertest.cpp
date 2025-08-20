/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcommandlineparsertest.h"
#include <QTest>
QTEST_GUILESS_MAIN(KAIChatCommandLineParserTest)

KAIChatCommandLineParserTest::KAIChatCommandLineParserTest(QObject *parent)
    : QObject{parent}
{
}

#include "moc_kaichatcommandlineparsertest.cpp"
