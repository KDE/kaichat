/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "kaichatexportchatasbasejob.h"
#include "libkaichatcore_export.h"

class LIBKAICHATCORE_EXPORT KAIChatExportChatAsTextJob : public KAIChatExportChatAsBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsTextJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsTextJob() override;

protected:
    void exportChat() override;
};
