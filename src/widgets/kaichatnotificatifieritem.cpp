/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatnotificatifieritem.h"
using namespace Qt::Literals::StringLiterals;

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
    setIconByPixmap(QIcon(u":/icons/systray.png"_s));
    setCategory(KStatusNotifierItem::ApplicationStatus);
}

#include "moc_kaichatnotificatifieritem.cpp"
