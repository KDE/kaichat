/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatimportchatjobtest.h"
#include "kaichatimportchatjob.h"
#include <QTest>
QTEST_GUILESS_MAIN(KAIChatImportChatJobTest)

KAIChatImportChatJobTest::KAIChatImportChatJobTest(QObject *parent)
    : QObject{parent}
{
}

void KAIChatImportChatJobTest::shouldHaveDefaultValues()
{
    KAIChatImportChatJob job;
    QVERIFY(job.fileName().isEmpty());
}

#include "moc_kaichatimportchatjobtest.cpp"
