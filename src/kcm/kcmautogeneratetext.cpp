/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kcmautogeneratetext.h"
#include <KPluginFactory>
#include <QVBoxLayout>

K_PLUGIN_CLASS_WITH_JSON(KCMAutoGenerateText, "kcm_autogeneratetext.json")

KCMAutoGenerateText::KCMAutoGenerateText(QObject *parent, const KPluginMetaData &data)
    : KCModule(parent, data)
{
    auto topLayout = new QVBoxLayout(widget());
    // TODO
}

#include "kcmautogeneratetext.moc"
#include "moc_kcmautogeneratetext.cpp"
