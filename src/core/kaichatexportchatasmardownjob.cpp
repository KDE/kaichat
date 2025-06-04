/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatexportchatasmardownjob.h"
#include "kaichat_core_debug.h"
#include <KLocalizedString>
#include <QFile>

KAIChatExportChatAsMardownJob::KAIChatExportChatAsMardownJob(QObject *parent)
    : KAIChatExportChatAsBaseJob{parent}
{
}

KAIChatExportChatAsMardownJob::~KAIChatExportChatAsMardownJob() = default;

void KAIChatExportChatAsMardownJob::exportChat()
{
    QString txt;
    txt = QStringLiteral("# %1").arg(mInfo.chatTitle);
    for (const auto &message : mInfo.listMessages) {
        txt += QLatin1Char('\n');
        txt += QLatin1Char('\n');
        switch (message.sender()) {
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Unknown:
            qCWarning(KAICHAT_CORE_LOG) << "Sender invalid";
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::User:
            txt += QStringLiteral("## %1").arg(i18n("User"));
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Assistant:
            txt += QStringLiteral("## %1").arg(i18n("Assistant"));
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::System:
            txt += QStringLiteral("## %1").arg(i18n("System"));
            break;
        }
        txt += QLatin1Char('\n');
        txt += QLatin1Char('\n');
        txt += message.content();
    }
    QFile data(mInfo.filename);
    if (data.open(QFile::WriteOnly)) {
        QTextStream out(&data);
        out << txt;
    }
    deleteLater();
}

#include "moc_kaichatexportchatasmardownjob.cpp"
