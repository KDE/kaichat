/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasechatwidget.h"
#include "exploredatabasechatiddelegate.h"
#include "exploredatabasetooltipdelegate.h"
#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <QTableWidget>
#include <TextAutoGenerateText/TextAutoGenerateLocalChatsDatabase>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateManager>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseChatWidget::KAIChatDatabaseChatWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
    mTableView->setItemDelegateForColumn(1, new ExploreDatabaseTooltipDelegate(this));
    if (mManager) {
        mTableView->setItemDelegateForColumn(0, new ExploreDatabaseChatIdDelegate(mManager, this));
        mModel = mManager->databaseManager()->chatsDatabase()->createChatsModel();
        if (mModel) {
            setModel(mModel.get());
        } else {
            qCWarning(KAICHAT_WIDGET_LOG) << "Model is not defined";
        }
    }
}

KAIChatDatabaseChatWidget::~KAIChatDatabaseChatWidget() = default;

#include "moc_kaichatdatabasechatwidget.cpp"
