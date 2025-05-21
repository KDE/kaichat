/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QObject>

class KAIChatImportChatJobTest : public QObject
{
    Q_OBJECT
public:
    explicit KAIChatImportChatJobTest(QObject *parent = nullptr);
    ~KAIChatImportChatJobTest() override = default;
private Q_SLOTS:
    void shouldHaveDefaultValues();
};
