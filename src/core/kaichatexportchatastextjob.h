/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"
#include <TextAutoGenerateText/TextAutoGenerateExportChatBaseJob>

class LIBKAICHATCORE_EXPORT KAIChatExportChatAsTextJob : public TextAutoGenerateText::TextAutoGenerateExportChatBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsTextJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsTextJob() override;

protected:
    void exportChat() override;
};
