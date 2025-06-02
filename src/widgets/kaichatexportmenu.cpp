/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatexportmenu.h"
#include <KLocalizedString>
KAIChatExportMenu::KAIChatExportMenu(QObject *parent)
    : KActionMenu(parent)
{
    setText(i18nc("@action:inmenu", "Export…"));
    auto act = new QAction(i18nc("@action", "Export as Json…"), this);
    connect(act, &QAction::triggered, this, &KAIChatExportMenu::slotExportAsJson);
    addAction(act);

    act = new QAction(i18nc("@action", "Export as Markdown…"), this);
    connect(act, &QAction::triggered, this, &KAIChatExportMenu::slotExportAsMarkdown);
    addAction(act);

    act = new QAction(i18nc("@action", "Export as Text…"), this);
    connect(act, &QAction::triggered, this, &KAIChatExportMenu::slotExportAsText);
    addAction(act);
}

KAIChatExportMenu::~KAIChatExportMenu() = default;

void KAIChatExportMenu::slotExportAsJson()
{
    // TODO
}

void KAIChatExportMenu::slotExportAsMarkdown()
{
    // TODO
}

void KAIChatExportMenu::slotExportAsText()
{
    // TODO
}

#include "moc_kaichatexportmenu.cpp"
