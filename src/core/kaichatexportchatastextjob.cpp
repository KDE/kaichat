/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatastextjob.h"

KAIChatExportChatAsTextJob::KAIChatExportChatAsTextJob(QObject *parent)
    : KAIChatExportChatAsBaseJob{parent}
{
}

KAIChatExportChatAsTextJob::~KAIChatExportChatAsTextJob() = default;

void KAIChatExportChatAsTextJob::start()
{
    // TODO
}

#include "moc_kaichatexportchatastextjob.cpp"
