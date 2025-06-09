/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatconfigureinstanceswidget.h"
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateTextInstancesManagerWidget>
KAIChatConfigureInstancesWidget::KAIChatConfigureInstancesWidget(QWidget *parent)
    : QWidget{parent}
    , mInstancesManagerWidget(new TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget(this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(QStringLiteral("mainLayout"));
    mainLayout->setContentsMargins({});

    mInstancesManagerWidget->setObjectName(QStringLiteral("mInstancesManagerWidget"));
    mainLayout->addWidget(mInstancesManagerWidget);
}

KAIChatConfigureInstancesWidget::~KAIChatConfigureInstancesWidget() = default;

void KAIChatConfigureInstancesWidget::save()
{
    // TODO
}

void KAIChatConfigureInstancesWidget::load()
{
    // TODO
}

#include "moc_kaichatconfigureinstanceswidget.cpp"
