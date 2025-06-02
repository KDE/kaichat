/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatasbasejobtest.h"
#include "kaichatexportchatasbasejob.h"
#include <QTest>
QTEST_GUILESS_MAIN(KAIChatExportChatAsBaseJobTest)

KAIChatExportChatAsBaseJobTest::KAIChatExportChatAsBaseJobTest(QObject *parent)
    : QObject{parent}
{
}

void KAIChatExportChatAsBaseJobTest::shouldVerifyExportChatInfo()
{
    KAIChatExportChatAsBaseJob::ExportChatInfo info;
    QVERIFY(info.chatTitle.isEmpty());
    QVERIFY(info.filename.isEmpty());
}

#include "moc_kaichatexportchatasbasejobtest.cpp"
