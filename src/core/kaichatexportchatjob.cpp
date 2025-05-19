/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatjob.h"
#include "kaichat_core_debug.h"
KAIChatExportChatJob::KAIChatExportChatJob(QObject *parent)
    : QObject{parent}
{
}

KAIChatExportChatJob::~KAIChatExportChatJob() = default;

bool KAIChatExportChatJob::canStart() const
{
    if (mChatId.isEmpty()) {
        qCWarning(KAICHAT_CORE_LOG) << "ChatId is empty. It's a bug";
        return false;
    }
    return true;
}

QByteArray KAIChatExportChatJob::chatId() const
{
    return mChatId;
}

void KAIChatExportChatJob::setChatId(const QByteArray &newChatId)
{
    mChatId = newChatId;
}

#include "moc_kaichatexportchatjob.cpp"
