/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasewidget.h"
#include "databasedialog/kaichatdatabasechatpendingtypedinfowidget.h"
#include "databasedialog/kaichatdatabasechatwidget.h"
#include "databasedialog/kaichatdatabasemessagejsonwidget.h"
#include "databasedialog/kaichatdatabasemessageswidget.h"
#include <KLocalizedString>
#include <QTabWidget>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseWidget::KAIChatDatabaseWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
    , mTabWidget(new QTabWidget(this))
    , mDatabaseChatWidget(new KAIChatDatabaseChatWidget(manager, this))
    , mDatabaseChatPendingTypedInfoWidget(new KAIChatDatabaseChatPendingTypedInfoWidget(manager, this))
    , mDatabaseMessagesWidget(new KAIChatDatabaseMessagesWidget(manager, this))
    , mDatabaseMessageJsonWidget(new KAIChatDatabaseMessageJsonWidget(this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);

    mTabWidget->setObjectName("mTabWidget"_L1);
    mainLayout->addWidget(mTabWidget);

    mDatabaseChatWidget->setObjectName("mDatabaseChatWidget"_L1);
    mTabWidget->addTab(mDatabaseChatWidget, i18n("Chat"));

    mDatabaseMessagesWidget->setObjectName("mDatabaseMessagesWidget"_L1);
    mTabWidget->addTab(mDatabaseMessagesWidget, i18n("Messages in Database"));

    mDatabaseMessageJsonWidget->setObjectName("mDatabaseMessageJsonWidget"_L1);
    mTabWidget->addTab(mDatabaseMessageJsonWidget, i18n("Messages JSON"));

    mDatabaseChatPendingTypedInfoWidget->setObjectName("mDatabaseChatPendingTypedInfoWidget"_L1);
    mTabWidget->addTab(mDatabaseChatPendingTypedInfoWidget, i18n("Pending Typed Info"));
    connect(mDatabaseChatWidget, &KAIChatDatabaseChatWidget::showMessageFromChatIdRequested, this, [this](const QByteArray &chatId) {
        // TODO
        mDatabaseMessagesWidget->loadMessageFromChatId(QString::fromLatin1(chatId));
    });
}

KAIChatDatabaseWidget::~KAIChatDatabaseWidget() = default;

#include "moc_kaichatdatabasewidget.cpp"
