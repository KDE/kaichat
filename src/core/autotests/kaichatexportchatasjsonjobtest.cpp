/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatexportchatasjsonjobtest.h"
#include "kaichatexportchatasjsonjob.h"
#include <QTest>
QTEST_GUILESS_MAIN(KAIChatExportChatAsJsonJobTest)
KAIChatExportChatAsJsonJobTest::KAIChatExportChatAsJsonJobTest(QObject *parent)
    : QObject{parent}
{
}

#include "moc_kaichatexportchatasjsonjobtest.cpp"
