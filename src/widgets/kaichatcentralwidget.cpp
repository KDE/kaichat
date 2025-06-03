/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcentralwidget.h"
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateChatsModel>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateMessagesModel>
#include <TextAutoGenerateText/TextAutoGenerateWidget>
using namespace Qt::Literals::StringLiterals;
KAIChatCentralWidget::KAIChatCentralWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mTextAutogenerateWidget(new TextAutoGenerateText::TextAutoGenerateWidget(manager, this))
    , mManager(manager)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);

    mTextAutogenerateWidget->setObjectName("mTextAutogenerateWidget"_L1);
    mainLayout->addWidget(mTextAutogenerateWidget);
}

KAIChatCentralWidget::~KAIChatCentralWidget() = default;

void KAIChatCentralWidget::showArchive(bool checked)
{
    mManager->setShowArchived(checked);
}

void KAIChatCentralWidget::searchText()
{
    mTextAutogenerateWidget->slotSearchText();
}

QString KAIChatCentralWidget::chatCurrentTitle() const
{
    return mManager->textAutoGenerateChatsModel()->title(mManager->currentChatId());
}

QList<TextAutoGenerateText::TextAutoGenerateMessage> KAIChatCentralWidget::messagesFromCurrentChat() const
{
    return mManager->messagesModelFromChatId(mManager->currentChatId())->messages();
}

#include "moc_kaichatcentralwidget.cpp"
