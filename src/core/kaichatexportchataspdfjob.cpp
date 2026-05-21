/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchataspdfjob.h"

#include "kaichat_core_debug.h"
#include <KLocalizedString>
#include <QFile>
#include <QPainter>
#include <QPdfWriter>
#include <QTextDocument>

using namespace Qt::Literals::StringLiterals;
KAIChatExportChatAsPdfJob::KAIChatExportChatAsPdfJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateExportChatBaseJob{parent}
{
}

KAIChatExportChatAsPdfJob::~KAIChatExportChatAsPdfJob() = default;

QString KAIChatExportChatAsPdfJob::fileFilter()
{
    return u"%1 (*.pdf)"_s.arg(i18n("Pdf"));
}

void KAIChatExportChatAsPdfJob::exportChat()
{
    QTextDocument doc;
    QString txt;
    txt = mInfo.chatTitle;
    for (const auto &message : std::as_const(mInfo.listMessages)) {
        txt += message.htmlGenerated();
    }
    doc.setHtml(txt);
    QPdfWriter writer(mInfo.filename);
    // Page settings
    writer.setPageSize(QPageSize::A4);
    writer.setPageOrientation(QPageLayout::Portrait);
    writer.setResolution(300); // High DPI for quality
    writer.setTitle(u"Qt6 Generated PDF"_s);
    writer.setCreator(u"Qt6 PDF Generator"_s);

    // Render document to PDF
    QPainter painter(&writer);
    doc.drawContents(&painter);
    painter.end();
    deleteLater();
}

#include "moc_kaichatexportchataspdfjob.cpp"
