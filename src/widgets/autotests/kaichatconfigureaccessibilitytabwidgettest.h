/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>

class KAIChatConfigureAccessibilityTabWidgetTest : public QObject
{
    Q_OBJECT
public:
    explicit KAIChatConfigureAccessibilityTabWidgetTest(QObject *parent = nullptr);
    ~KAIChatConfigureAccessibilityTabWidgetTest() override = default;

private Q_SLOTS:
    void shouldHaveDefaultValues();
};
