/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include "databasedialog/exploredatabasebasestoragewidget.h"
#include <QWidget>

class KAIChatDatabaseChatWidget : public ExploreDatabaseBaseStorageWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseChatWidget(QWidget *parent = nullptr);
    ~KAIChatDatabaseChatWidget() override;
};
