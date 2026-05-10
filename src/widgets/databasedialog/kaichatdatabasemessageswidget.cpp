/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasemessageswidget.h"
#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateManager>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseMessagesWidget::KAIChatDatabaseMessagesWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
    if (mManager) {
#if 0
        mModel = mManager->databaseManager()->chatPendingTypedInfoDatabase()->createChatPendingInfoModel();
        if (mModel) {
            setModel(mModel.get());
        } else {
            qCWarning(KAICHAT_WIDGET_LOG) << "Model is not defined";
        }
#endif
    }
    // TODO
}

KAIChatDatabaseMessagesWidget::~KAIChatDatabaseMessagesWidget() = default;

#include "moc_kaichatdatabasemessageswidget.cpp"
