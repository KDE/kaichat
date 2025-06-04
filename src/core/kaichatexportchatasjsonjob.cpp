/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatasjsonjob.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

KAIChatExportChatAsJsonJob::KAIChatExportChatAsJsonJob(QObject *parent)
    : KAIChatExportChatAsBaseJob{parent}
{
}

KAIChatExportChatAsJsonJob::~KAIChatExportChatAsJsonJob() = default;

void KAIChatExportChatAsJsonJob::exportChat()
{
    QJsonObject obj;
    QJsonArray messages;
    for (const auto &message : mInfo.listMessages) {
        const QByteArray ba = TextAutoGenerateText::TextAutoGenerateMessage::serialize(message, false);
        const QJsonDocument d = QJsonDocument::fromJson(ba);
        messages.append(d.object());
        // qDebug() << " ba " << ba;
    }
    obj[QStringLiteral("messages")] = messages;
    obj[QStringLiteral("title")] = mInfo.chatTitle;
    // qDebug() << " obj" << QJsonDocument(obj).toJson();
    QFile data(mInfo.filename);
    if (data.open(QFile::WriteOnly)) {
        QTextStream out(&data);
        out << QJsonDocument(obj).toJson();
    }
    deleteLater();
}

#include "moc_kaichatexportchatasjsonjob.cpp"
