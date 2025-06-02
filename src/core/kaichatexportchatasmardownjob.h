/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "kaichatexportchatasbasejob.h"
#include "libkaichatcore_export.h"
#include <QObject>

class LIBKAICHATCORE_EXPORT KAIChatExportChatAsMardownJob : public KAIChatExportChatAsBaseJob
{
    Q_OBJECT
public:
    explicit KAIChatExportChatAsMardownJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsMardownJob() override;

protected:
    void exportChat() override;
};
