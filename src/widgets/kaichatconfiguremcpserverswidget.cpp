/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfiguremcpserverswidget.h"
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateTextMcpServerWidget>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureMcpServersWidget::KAIChatConfigureMcpServersWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mMcpServerWidget(new TextAutoGenerateText::TextAutoGenerateTextMcpServerWidget(manager, this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mMcpServerWidget->setObjectName(u"mMcpServerWidget"_s);
    mainLayout->addWidget(mMcpServerWidget);
}

KAIChatConfigureMcpServersWidget::~KAIChatConfigureMcpServersWidget() = default;

void KAIChatConfigureMcpServersWidget::save()
{
}

void KAIChatConfigureMcpServersWidget::load()
{
}

void KAIChatConfigureMcpServersWidget::restoreToDefaults()
{
}

#include "moc_kaichatconfiguremcpserverswidget.cpp"
