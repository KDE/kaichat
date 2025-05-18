/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatjob.h"

KAIChatExportChatJob::KAIChatExportChatJob(QObject *parent)
    : QObject{parent}
{
}

KAIChatExportChatJob::~KAIChatExportChatJob() = default;

#include "moc_kaichatexportchatjob.cpp"
