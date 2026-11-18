/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfiguremcpserverswidget.h"
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateTextConfigureMcpServersWidget>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureMcpServersWidget::KAIChatConfigureMcpServersWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mConfigureMcpServersWidget(new TextAutoGenerateText::TextAutoGenerateTextConfigureMcpServersWidget(manager, this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    // Changes are applied when dialog is accepted
    mConfigureMcpServersWidget->setObjectName(u"mConfigureMcpServersWidget"_s);
    mainLayout->addWidget(mConfigureMcpServersWidget);
}

KAIChatConfigureMcpServersWidget::~KAIChatConfigureMcpServersWidget() = default;

void KAIChatConfigureMcpServersWidget::save()
{
    mConfigureMcpServersWidget->save();
}

void KAIChatConfigureMcpServersWidget::load()
{
    mConfigureMcpServersWidget->load();
}

void KAIChatConfigureMcpServersWidget::restoreToDefaults()
{
    // nothing
}

#include "moc_kaichatconfiguremcpserverswidget.cpp"
