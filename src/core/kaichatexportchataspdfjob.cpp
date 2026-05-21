/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportchataspdfjob.h"

#include "kaichat_core_debug.h"
#include <KLocalizedString>
#include <QFile>
#include <QPageLayout>
#include <QPageSize>
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
    QPdfWriter writer(mInfo.filename);
    writer.setPageSize(QPageSize::A4);
    writer.setPageOrientation(QPageLayout::Portrait);
    writer.setPageMargins(QMarginsF(10, 10, 10, 10), QPageLayout::Millimeter);
    writer.setResolution(300); // High DPI for quality
    writer.setTitle(mInfo.chatTitle);
    writer.setCreator(u"KAIChat PDF Generator"_s);

    // setResolution(300) means the QPainter coordinate space is in 300-DPI dots.
    // Convert the paint area from mm to dots at the writer's resolution so the
    // document fills the full page.
    const QSizeF paintMM = writer.pageLayout().paintRect(QPageLayout::Millimeter).size();
    const double dotsPerMM = writer.resolution() / 25.4;
    const QSizeF pageSize(paintMM.width() * dotsPerMM, paintMM.height() * dotsPerMM);

    QTextDocument doc;
    doc.setPageSize(pageSize);
    QFont f;
    f.setPointSize(24);
    doc.setDefaultFont(f);
    QString txt = mInfo.chatTitle;
    for (const auto &message : std::as_const(mInfo.listMessages)) {
        txt += message.htmlGenerated();
    }
    doc.setHtml(txt);

    // Render document to PDF, page by page
    QPainter painter(&writer);
    const QRectF pageRect(QPointF(0, 0), pageSize);
    double pageTop = 0;
    bool firstPage = true;
    while (pageTop < doc.size().height()) {
        if (!firstPage) {
            writer.newPage();
        }
        firstPage = false;
        painter.save();
        painter.translate(0, -pageTop);
        doc.drawContents(&painter, pageRect.translated(0, pageTop));
        painter.restore();
        pageTop += pageSize.height();
    }
    painter.end();
    deleteLater();
}

#include "moc_kaichatexportchataspdfjob.cpp"
