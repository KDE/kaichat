/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfiguremcpserverswidget.h"
#include <QVBoxLayout>
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
#include <TextAutoGenerateText/TextAutoGenerateTextConfigureMcpServersWidget>
#else
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateTextMcpProtocolCore/McpServerManager>
#include <TextAutoGenerateTextMcpProtocolWidgets/McpServerWidget>
#endif

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureMcpServersWidget::KAIChatConfigureMcpServersWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
    , mConfigureMcpServersWidget(new TextAutoGenerateText::TextAutoGenerateTextConfigureMcpServersWidget(manager, this))
#else
    , mMcpServerWidget(new TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget(manager->textAutoGenerateTextMcpServerManager()->mcpServerModel(), this))
    , mManager(manager)
#endif
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
    // Changes are applied when dialog is accepted
    mConfigureMcpServersWidget->setObjectName(u"mConfigureMcpServersWidget"_s);
    mainLayout->addWidget(mConfigureMcpServersWidget);
#else
    mMcpServerWidget->setObjectName(u"mMcpServerWidget"_s);
    mainLayout->addWidget(mMcpServerWidget);
    connect(mMcpServerWidget, &TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget::settingsChanged, this, &KAIChatConfigureMcpServersWidget::save);
    load();
#endif
}

KAIChatConfigureMcpServersWidget::~KAIChatConfigureMcpServersWidget() = default;

void KAIChatConfigureMcpServersWidget::save()
{
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
    mConfigureMcpServersWidget->save();
#else
    mManager->textAutoGenerateTextMcpServerManager()->saveServers();
#endif
}

void KAIChatConfigureMcpServersWidget::load()
{
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 2, 42)
    mConfigureMcpServersWidget->load();
#else
    mManager->textAutoGenerateTextMcpServerManager()->loadServers();
#endif
}

void KAIChatConfigureMcpServersWidget::restoreToDefaults()
{
    // nothing
}

#include "moc_kaichatconfiguremcpserverswidget.cpp"
