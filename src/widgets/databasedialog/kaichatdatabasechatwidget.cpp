/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasechatwidget.h"
#include <KLocalizedString>
#include <TextAutoGenerateText/TextAutoGenerateLocalDatabaseManager>
#include <TextAutoGenerateText/TextAutoGenerateManager>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseChatWidget::KAIChatDatabaseChatWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : ExploreDatabaseBaseStorageWidget{parent}
    , mManager(manager)
{
}

KAIChatDatabaseChatWidget::~KAIChatDatabaseChatWidget() = default;

#include "moc_kaichatdatabasechatwidget.cpp"
