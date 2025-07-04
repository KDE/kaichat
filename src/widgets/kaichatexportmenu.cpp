/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportmenu.h"
#include "kaichat_widget_debug.h"
#include "kaichatexportchatasmardownjob.h"
#include "kaichatexportchatastextjob.h"
#include <KLocalizedString>
#include <TextAutoGenerateText/TextAutoGenerateExportChatAsJsonJob>

KAIChatExportMenu::KAIChatExportMenu(QObject *parent)
    : KActionMenu(parent)
{
    setText(i18nc("@action:inmenu", "Export…"));
    auto act = new QAction(i18nc("@action", "Export as Json…"), this);
    connect(act, &QAction::triggered, this, [this] {
        mConvertToType = ConvertToType::Json;
        Q_EMIT exportInfoRequested();
    });
    addAction(act);

    act = new QAction(i18nc("@action", "Export as Markdown…"), this);
    connect(act, &QAction::triggered, this, [this] {
        mConvertToType = ConvertToType::Markdown;
        Q_EMIT exportInfoRequested();
    });
    addAction(act);

    act = new QAction(i18nc("@action", "Export as Text…"), this);
    connect(act, &QAction::triggered, this, [this] {
        mConvertToType = ConvertToType::Text;
        Q_EMIT exportInfoRequested();
    });
    addAction(act);
}

KAIChatExportMenu::~KAIChatExportMenu() = default;

void KAIChatExportMenu::setExportChatInfo(const TextAutoGenerateText::TextAutoGenerateExportChatBaseJob::ExportChatInfo &newInfo)
{
    convertChat(newInfo);
}

void KAIChatExportMenu::convertChat(const TextAutoGenerateText::TextAutoGenerateExportChatBaseJob::ExportChatInfo &newInfo)
{
    TextAutoGenerateText::TextAutoGenerateExportChatBaseJob *job = nullptr;
    switch (mConvertToType) {
    case ConvertToType::Unknown:
        qCWarning(KAICHAT_WIDGET_LOG) << " Invalid ConvertToType enum. It's a bug";
        return;
    case ConvertToType::Json:
        job = new TextAutoGenerateText::TextAutoGenerateExportChatAsJsonJob(this);
        break;
    case ConvertToType::Markdown:
        job = new KAIChatExportChatAsMardownJob(this);
        break;
    case ConvertToType::Text:
        job = new KAIChatExportChatAsTextJob(this);
        break;
    }
    connect(job, &TextAutoGenerateText::TextAutoGenerateExportChatBaseJob::exportDone, this, []() {
        qDebug() << " job done";
    });

    job->setInfo(newInfo);
    job->start();
}

#include "moc_kaichatexportmenu.cpp"
