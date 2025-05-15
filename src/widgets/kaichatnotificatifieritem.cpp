/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatnotificatifieritem.h"
#include <KLocalizedString>
KAIChatNotificatifierItem::KAIChatNotificatifierItem(QObject *parent)
    : KStatusNotifierItem{parent}
{
    createTrayIcon();
}

KAIChatNotificatifierItem::~KAIChatNotificatifierItem() = default;

void KAIChatNotificatifierItem::createTrayIcon()
{
    setToolTipTitle(i18n("KAIChat"));
    setStatus(Active);
    setIconByPixmap(QIcon(QStringLiteral(":/icons/systray.png")));
    setCategory(KStatusNotifierItem::ApplicationStatus);
}

#include "moc_kaichatnotificatifieritem.cpp"
