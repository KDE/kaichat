/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasechatpendingtypedinfowidget.h"
#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateLocalChatPendingTypedInfoDatabase>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateManager>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseChatPendingTypedInfoWidget::KAIChatDatabaseChatPendingTypedInfoWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
    if (mManager) {
        mModel = mManager->databaseManager()->chatPendingTypedInfoDatabase()->createChatPendingInfoModel();
        if (mModel) {
            setModel(mModel.get());
        } else {
            qCWarning(KAICHAT_WIDGET_LOG) << "Model is not defined";
        }
    }
}

KAIChatDatabaseChatPendingTypedInfoWidget::~KAIChatDatabaseChatPendingTypedInfoWidget() = default;

#include "moc_kaichatdatabasechatpendingtypedinfowidget.cpp"
