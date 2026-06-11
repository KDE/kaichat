/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatdatabaseselectchatlineedittest.h"
#include "databasedialog/kaichatdatabaseselectchatlineedit.h"
#include <QTest>
QTEST_MAIN(KAIChatDatabaseSelectChatLineEditTest)

KAIChatDatabaseSelectChatLineEditTest::KAIChatDatabaseSelectChatLineEditTest(QObject *parent)
    : QObject{parent}
{
}

void KAIChatDatabaseSelectChatLineEditTest::shouldHaveDefaultValues()
{
    const KAIChatDatabaseSelectChatLineEdit w;
    QVERIFY(w.isClearButtonEnabled());
}

#include "moc_kaichatdatabaseselectchatlineedittest.cpp"
