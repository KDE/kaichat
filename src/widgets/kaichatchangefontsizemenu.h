/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <KActionMenu>

class KAIChatChangeFontSizeMenu : public KActionMenu
{
    Q_OBJECT
public:
    explicit KAIChatChangeFontSizeMenu(QObject *parent = nullptr);
    ~KAIChatChangeFontSizeMenu() override;

Q_SIGNALS:
    void fontChanged();

private:
    void changeFontSize(int offset);
};
