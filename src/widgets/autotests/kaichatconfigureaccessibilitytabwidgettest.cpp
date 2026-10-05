/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "kaichatconfigureaccessibilitytabwidgettest.h"

#include "configure/kaichatconfigureaccessibilitytabwidget.h"
#include <QStandardPaths>
#include <QTest>
QTEST_MAIN(KAIChatConfigureAccessibilityTabWidgetTest)

KAIChatConfigureAccessibilityTabWidgetTest::KAIChatConfigureAccessibilityTabWidgetTest(QObject *parent)
    : QObject{parent}
{
    QStandardPaths::setTestModeEnabled(true);
}

void KAIChatConfigureAccessibilityTabWidgetTest::shouldHaveDefaultValues()
{
    const KAIChatConfigureAccessibilityTabWidget w;
    QVERIFY(w.tabBarAutoHide());
}

#include "moc_kaichatconfigureaccessibilitytabwidgettest.cpp"
