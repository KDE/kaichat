/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"
#include <QObject>
#include <TextAutoGenerateText/TextAutoGenerateExportChatBaseJob>

class LIBKAICHATCORE_EXPORT KAIChatExportChatAsMardownJob : public TextAutoGenerateText::TextAutoGenerateExportChatBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsMardownJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsMardownJob() override;

protected:
    void exportChat() override;
};
