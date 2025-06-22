/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include "libkaichatcore_export.h"
#include <TextAutoGenerateText/TextAutoGenerateExportChatBaseJob>
class LIBKAICHATCORE_EXPORT KAIChatExportChatAsJsonJob : public TextAutoGenerateText::TextAutoGenerateExportChatBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsJsonJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsJsonJob() override;

protected:
    void exportChat() override;
};
