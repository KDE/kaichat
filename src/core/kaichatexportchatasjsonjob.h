/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include "kaichatexportchatasbasejob.h"
#include "libkaichatcore_export.h"
class LIBKAICHATCORE_EXPORT KAIChatExportChatAsJsonJob : public KAIChatExportChatAsBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsJsonJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsJsonJob() override;

protected:
    void exportChat() override;
};
