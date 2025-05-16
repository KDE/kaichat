/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatconfiguregeneralwidget.h"
#include <QVBoxLayout>

KAIChatConfigureGeneralWidget::KAIChatConfigureGeneralWidget(QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(QStringLiteral("mainLayout"));
}

KAIChatConfigureGeneralWidget::~KAIChatConfigureGeneralWidget() = default;

#include "moc_kaichatconfiguregeneralwidget.cpp"
