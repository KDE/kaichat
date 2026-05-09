/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasechatpendingtypedinfowidget.h"
#include <KLocalizedString>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateManager>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseChatPendingTypedInfoWidget::KAIChatDatabaseChatPendingTypedInfoWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);

    // TODO
}

KAIChatDatabaseChatPendingTypedInfoWidget::~KAIChatDatabaseChatPendingTypedInfoWidget() = default;

#include "moc_kaichatdatabasechatpendingtypedinfowidget.cpp"
