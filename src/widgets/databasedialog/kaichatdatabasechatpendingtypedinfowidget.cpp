/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasechatpendingtypedinfowidget.h"
#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <textautogeneratetext/textautogeneratelocalchatsdatabase.h>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseChatPendingTypedInfoWidget::KAIChatDatabaseChatPendingTypedInfoWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
    if (mManager) {
#if 0
        mModel = mManager->databaseManager()->chatsDatabase()->;
        if (mModel) {
            setModel(mModel.get());
        } else {
            qCWarning(KAICHAT_WIDGET_LOG) << "Model is not defined";
        }
#endif
    }
}

KAIChatDatabaseChatPendingTypedInfoWidget::~KAIChatDatabaseChatPendingTypedInfoWidget() = default;

#include "moc_kaichatdatabasechatpendingtypedinfowidget.cpp"
