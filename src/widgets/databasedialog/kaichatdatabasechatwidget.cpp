/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasechatwidget.h"
#include <KLocalizedString>
#include <QVBoxLayout>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseChatWidget::KAIChatDatabaseChatWidget(QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);

    // TODO
}

KAIChatDatabaseChatWidget::~KAIChatDatabaseChatWidget() = default;

#include "moc_kaichatdatabasechatwidget.cpp"
