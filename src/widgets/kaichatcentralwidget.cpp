/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcentralwidget.h"
#include <QVBoxLayout>
#include <TextAutogenerateText/TextAutogenerateWidget>
using namespace Qt::Literals::StringLiterals;
KAIChatCentralWidget::KAIChatCentralWidget(QWidget *parent)
    : QWidget{parent}
    , mTextAutogenerateWidget(new TextAutogenerateText::TextAutogenerateWidget(this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("dd"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->addWidget(mTextAutogenerateWidget);
}

KAIChatCentralWidget::~KAIChatCentralWidget() = default;

#include "moc_kaichatcentralwidget.cpp"
