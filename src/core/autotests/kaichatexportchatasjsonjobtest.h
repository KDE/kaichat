/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QObject>

class KAIChatExportChatAsJsonJobTest : public QObject
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsJsonJobTest(QObject *parent = nullptr);
    ~KAIChatExportChatAsJsonJobTest() override = default;
};
