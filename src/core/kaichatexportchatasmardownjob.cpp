/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatexportchatasmardownjob.h"

KAIChatExportChatAsMardownJob::KAIChatExportChatAsMardownJob(QObject *parent)
    : KAIChatExportChatAsBaseJob{parent}
{
}

KAIChatExportChatAsMardownJob::~KAIChatExportChatAsMardownJob() = default;

void KAIChatExportChatAsMardownJob::exportChat()
{
    // TODO
    deleteLater();
}

#include "moc_kaichatexportchatasmardownjob.cpp"
