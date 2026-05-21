/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"
#include <TextAutoGenerateText/TextAutoGenerateExportChatBaseJob>

class LIBKAICHATCORE_EXPORT KAIChatExportChatAsPdfJob : public TextAutoGenerateText::TextAutoGenerateExportChatBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsPdfJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsPdfJob() override;

    [[nodiscard]] static QString fileFilter();

protected:
    void exportChat() override;
};
