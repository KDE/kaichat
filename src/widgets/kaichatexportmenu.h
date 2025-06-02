/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include <KActionMenu>
class KAIChatExportMenu : public KActionMenu
{
    Q_OBJECT
public:
    explicit KAIChatExportMenu(QObject *parent = nullptr);
    ~KAIChatExportMenu() override;

private:
    void slotExportAsJson();
    void slotExportAsMarkdown();
    void slotExportAsText();
};
