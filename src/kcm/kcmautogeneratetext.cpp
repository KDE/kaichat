/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kcmautogeneratetext.h"
#include <KLocalizedString>
#include <KPluginFactory>
#include <QTabWidget>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateTextInstancesManagerWidget>
#include <TextAutoGenerateTextMcpProtocolCore/McpServerManager>
#include <TextAutoGenerateTextMcpProtocolWidgets/McpServerWidget>
K_PLUGIN_CLASS_WITH_JSON(KCMAutoGenerateText, "kcm_autogeneratetext.json")

KCMAutoGenerateText::KCMAutoGenerateText(QObject *parent, const KPluginMetaData &data)
    : KCModule(parent, data)
{
    auto topLayout = new QVBoxLayout(widget());
    auto manager = new TextAutoGenerateText::TextAutoGenerateManager(this);
    manager->loadEngine();
    auto tabWidget = new QTabWidget(widget());

    mManagerWidget = new TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget(manager, widget());
    tabWidget->addTab(mManagerWidget, i18n("Instances"));
    mMcpProtocolWidget =
        new TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget(manager->textAutoGenerateTextMcpServerManager()->mcpServerModel(), widget());
    tabWidget->addTab(mMcpProtocolWidget, i18n("MCP Server"));
    topLayout->addWidget(tabWidget);
}

void KCMAutoGenerateText::load()
{
}

void KCMAutoGenerateText::save()
{
    mManagerWidget->save();
}

void KCMAutoGenerateText::defaults()
{
}

#include "kcmautogeneratetext.moc"
#include "moc_kcmautogeneratetext.cpp"
