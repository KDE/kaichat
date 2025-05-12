/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcentralwidget.h"
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateWidget>
using namespace Qt::Literals::StringLiterals;
KAIChatCentralWidget::KAIChatCentralWidget(QWidget *parent)
    : QWidget{parent}
    , mManager(new TextAutoGenerateText::TextAutoGenerateManager(this))
    , mTextAutogenerateWidget(new TextAutoGenerateText::TextAutoGenerateWidget(mManager, this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->addWidget(mTextAutogenerateWidget);
}

KAIChatCentralWidget::~KAIChatCentralWidget() = default;

void KAIChatCentralWidget::showArchive(bool checked)
{
    mManager->setShowArchived(checked);
}

#include "moc_kaichatcentralwidget.cpp"
