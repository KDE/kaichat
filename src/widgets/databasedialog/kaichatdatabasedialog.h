/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include <QDialog>
class KAIChatDatabaseWidget;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class KAIChatDatabaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseDialog(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseDialog() override;

private:
    KAIChatDatabaseWidget *const mDatabaseWidget;
};
