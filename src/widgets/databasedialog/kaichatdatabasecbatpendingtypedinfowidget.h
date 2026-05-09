/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include "databasedialog/exploredatabasebasestoragewidget.h"
#include <QWidget>
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class KAIChatDatabaseCbatPendingTypedInfoWidget : public ExploreDatabaseBaseStorageWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseCbatPendingTypedInfoWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseCbatPendingTypedInfoWidget() override;

private:
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
};
