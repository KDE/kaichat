/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kcmautogeneratetext.h"
#include <KPluginFactory>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateTextInstancesManagerWidget>
K_PLUGIN_CLASS_WITH_JSON(KCMAutoGenerateText, "kcm_autogeneratetext.json")

KCMAutoGenerateText::KCMAutoGenerateText(QObject *parent, const KPluginMetaData &data)
    : KCModule(parent, data)
{
    auto topLayout = new QVBoxLayout(widget());
    auto manager = new TextAutoGenerateText::TextAutoGenerateManager;
    manager->loadEngine();
    mManagerWidget = new TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget(manager, widget());
    topLayout->addWidget(mManagerWidget);
}

void KCMAutoGenerateText::load()
{
    // TODO
}

void KCMAutoGenerateText::save()
{
    mManagerWidget->save();
}

void KCMAutoGenerateText::defaults()
{
    // TODO
}

#include "kcmautogeneratetext.moc"
#include "moc_kcmautogeneratetext.cpp"
