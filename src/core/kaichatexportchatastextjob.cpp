/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchatastextjob.h"

#include "kaichat_core_debug.h"
#include <KLocalizedString>
#include <QFile>

using namespace Qt::Literals::StringLiterals;
KAIChatExportChatAsTextJob::KAIChatExportChatAsTextJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateExportChatBaseJob{parent}
{
}

KAIChatExportChatAsTextJob::~KAIChatExportChatAsTextJob() = default;

void KAIChatExportChatAsTextJob::exportChat()
{
    QString txt;
    txt = mInfo.chatTitle;
    for (const auto &message : std::as_const(mInfo.listMessages)) {
        txt += u'\n';
        switch (message.sender()) {
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Unknown:
            qCWarning(KAICHAT_CORE_LOG) << "Sender invalid";
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::User:
            txt += i18n("User");
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Assistant:
            txt += i18n("Assistant");
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::System:
            txt += i18n("System");
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Tool:
            txt += i18n("Tool");
            break;
        }
        txt += u"------------------------"_s;
        txt += u'\n';
        txt += message.content();
        txt += u'\n';
    }
    QFile data(mInfo.filename);
    if (data.open(QFile::WriteOnly)) {
        QTextStream out(&data);
        out << txt;
    }
    deleteLater();
}

#include "moc_kaichatexportchatastextjob.cpp"
