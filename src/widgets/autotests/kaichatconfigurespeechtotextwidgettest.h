/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>

class KAIChatConfigureSpeechToTextWidgetTest : public QObject
{
    Q_OBJECT
public:
    explicit KAIChatConfigureSpeechToTextWidgetTest(QObject *parent = nullptr);
    ~KAIChatConfigureSpeechToTextWidgetTest() override = default;

private Q_SLOTS:
    void shouldHaveDefaultValues();
};
