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
    , mManager(new TextAutoGenerateText::TextAutoGenerateManager(this))
{
    auto topLayout = new QVBoxLayout(widget());
    mManager->loadEngine();
    auto tabWidget = new QTabWidget(widget());

    mManagerWidget = new TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget(mManager, widget());
    tabWidget->addTab(mManagerWidget, i18n("Instances"));
    connect(mManagerWidget, &TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget::settingsChanged, this, &KCModule::needsSaveChanged);
    mMcpProtocolWidget =
        new TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget(mManager->textAutoGenerateTextMcpServerManager()->mcpServerModel(), widget());
    connect(mMcpProtocolWidget, &TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget::settingsChanged, this, &KCModule::needsSaveChanged);
    tabWidget->addTab(mMcpProtocolWidget, i18n("MCP Server"));
    topLayout->addWidget(tabWidget);
}

void KCMAutoGenerateText::load()
{
}

void KCMAutoGenerateText::save()
{
    mManagerWidget->save();
    mManager->textAutoGenerateTextMcpServerManager()->saveServers();
}

void KCMAutoGenerateText::defaults()
{
}

#include "kcmautogeneratetext.moc"
#include "moc_kcmautogeneratetext.cpp"
