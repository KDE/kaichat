/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatasjsonjob.h"

KAIChatExportChatAsJsonJob::KAIChatExportChatAsJsonJob(QObject *parent)
    : KAIChatExportChatAsBaseJob{parent}
{
}

KAIChatExportChatAsJsonJob::~KAIChatExportChatAsJsonJob() = default;

void KAIChatExportChatAsJsonJob::start()
{
    // TODO
}

#include "moc_kaichatexportchatasjsonjob.cpp"
