/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatasbasejob.h"

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

QDebug operator<<(QDebug d, const KAIChatExportChatAsBaseJob::ExportChatInfo &t)
{
    d.space() << "filename:" << t.filename;
    d.space() << "chatTitle:" << t.chatTitle;
    return d;
}

bool KAIChatExportChatAsBaseJob::ExportChatInfo::isValid() const
{
    // TODO add more
    return !filename.isEmpty();
}

#include "moc_kaichatexportchatasbasejob.cpp"
