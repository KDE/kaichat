/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatconfigureinstanceswidget.h"
using namespace Qt::Literals::StringLiterals;

#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateTextInstancesManagerWidget>
KAIChatConfigureInstancesWidget::KAIChatConfigureInstancesWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mInstancesManagerWidget(new TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget(manager, this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mInstancesManagerWidget->setObjectName(u"mInstancesManagerWidget"_s);
    mainLayout->addWidget(mInstancesManagerWidget);
}

KAIChatConfigureInstancesWidget::~KAIChatConfigureInstancesWidget() = default;

void KAIChatConfigureInstancesWidget::save()
{
    mInstancesManagerWidget->save();
}

void KAIChatConfigureInstancesWidget::load()
{
    // nothing
}

void KAIChatConfigureInstancesWidget::restoreToDefaults()
{
    // nothing
}

#include "moc_kaichatconfigureinstanceswidget.cpp"
