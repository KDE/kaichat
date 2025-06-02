/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include "kaichatexportchatasbasejob.h"

class KAIChatExportChatAsTextJob : public KAIChatExportChatAsBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsTextJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsTextJob() override;
    void start() override;
};
