/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatasbasejob.h"
#include "kaichat_core_debug.h"

KAIChatExportChatAsBaseJob::KAIChatExportChatAsBaseJob(QObject *parent)
    : QObject{parent}
{
}

KAIChatExportChatAsBaseJob::~KAIChatExportChatAsBaseJob() = default;

KAIChatExportChatAsBaseJob::ExportChatInfo KAIChatExportChatAsBaseJob::info() const
{
    return mInfo;
}

void KAIChatExportChatAsBaseJob::setInfo(const ExportChatInfo &newInfo)
{
    mInfo = newInfo;
}

bool KAIChatExportChatAsBaseJob::canStart() const
{
    return mInfo.isValid();
}

void KAIChatExportChatAsBaseJob::start()
{
    if (!canStart()) {
        qCWarning(KAICHAT_CORE_LOG) << " Impossible to start job";
        deleteLater();
        return;
    }
    exportChat();
}

QDebug operator<<(QDebug d, const KAIChatExportChatAsBaseJob::ExportChatInfo &t)
{
    d.space() << "filename:" << t.filename;
    d.space() << "chatTitle:" << t.chatTitle;
    d.space() << "listMessages:" << t.listMessages;
    return d;
}

bool KAIChatExportChatAsBaseJob::ExportChatInfo::isValid() const
{
    // TODO add more
    return !filename.isEmpty();
}

#include "moc_kaichatexportchatasbasejob.cpp"
