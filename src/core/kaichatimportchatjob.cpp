/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatimportchatjob.h"

KAIChatImportChatJob::KAIChatImportChatJob(QObject *parent)
    : QObject{parent}
{
}

const QString &KAIChatImportChatJob::fileName() const
{
    return mFileName;
}

void KAIChatImportChatJob::setFileName(const QString &newFileName)
{
    mFileName = newFileName;
}

KAIChatImportChatJob::~KAIChatImportChatJob() = default;

#include "moc_kaichatimportchatjob.cpp"
