/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatexportchatjobtest.h"
#include "kaichatexportchatjob.h"
#include <QTest>
QTEST_GUILESS_MAIN(KAIChatExportChatJobTest)

KAIChatExportChatJobTest::KAIChatExportChatJobTest(QObject *parent)
    : QObject{parent}
{
}

void KAIChatExportChatJobTest::shouldHaveDefaultValues()
{
    KAIChatExportChatJob job;
    QVERIFY(job.chatId().isEmpty());
    QVERIFY(job.fileName().isEmpty());
    QVERIFY(!job.canStart());
}

#include "moc_kaichatexportchatjobtest.cpp"
