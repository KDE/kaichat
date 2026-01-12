/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatimportmenu.h"
#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <TextAutoGenerateText/TextAutoGenerateImportChatAsJsonJob>
using namespace Qt::Literals::StringLiterals;
KAIChatImportMenu::KAIChatImportMenu(QObject *parent)
    : KActionMenu{parent}
{
    setText(i18nc("@action:inmenu", "Import…"));
    auto act = new QAction(i18nc("@action", "Import as JSON…"), this);
    connect(act, &QAction::triggered, this, [this] {
        mConvertFromType = ConvertFromType::Json;
        mFileFilter = u"%1 (*.kaichat, *.json)"_s.arg(i18n("kaichat"));
        Q_EMIT importRequested();
    });
    addAction(act);
}

KAIChatImportMenu::~KAIChatImportMenu() = default;

void KAIChatImportMenu::setImportChatInfo(const TextAutoGenerateText::TextAutoGenerateImportChatBaseJob::ImportChatInfo &newInfo)
{
    TextAutoGenerateText::TextAutoGenerateImportChatBaseJob *job = nullptr;
    switch (mConvertFromType) {
    case ConvertFromType::Json:
        job = new TextAutoGenerateText::TextAutoGenerateImportChatAsJsonJob(this);
        break;
    case ConvertFromType::Unknown:
        qCWarning(KAICHAT_WIDGET_LOG) << " Invalid ConvertFromType enum. It's a bug";
        return;
    }

    job->setInfo(newInfo);
    job->start();
}

QString KAIChatImportMenu::fileFilter() const
{
    return mFileFilter;
}

#include "moc_kaichatimportmenu.cpp"
