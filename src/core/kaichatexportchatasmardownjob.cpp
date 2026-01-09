/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatexportchatasmardownjob.h"

#include "kaichat_core_debug.h"
#include <KLocalizedString>
#include <QFile>

using namespace Qt::Literals::StringLiterals;
KAIChatExportChatAsMardownJob::KAIChatExportChatAsMardownJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateExportChatBaseJob{parent}
{
}

KAIChatExportChatAsMardownJob::~KAIChatExportChatAsMardownJob() = default;

void KAIChatExportChatAsMardownJob::exportChat()
{
    QString txt;
    txt = u"# %1"_s.arg(mInfo.chatTitle);
    for (const auto &message : std::as_const(mInfo.listMessages)) {
        txt += u'\n';
        txt += u'\n';
        switch (message.sender()) {
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Unknown:
            qCWarning(KAICHAT_CORE_LOG) << "Sender invalid";
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::User:
            txt += u"## %1"_s.arg(i18n("User"));
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Assistant:
            txt += u"## %1"_s.arg(i18n("Assistant"));
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::System:
            txt += u"## %1"_s.arg(i18n("System"));
            break;
        case TextAutoGenerateText::TextAutoGenerateMessage::Sender::Tool:
            txt += u"## %1"_s.arg(i18n("Tool"));
            break;
        }
        txt += u'\n';
        txt += u'\n';
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
