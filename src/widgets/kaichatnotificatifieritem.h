/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include <KStatusNotifierItem>

class KAIChatNotificatifierItem : public KStatusNotifierItem
{
    Q_OBJECT
public:
    explicit KAIChatNotificatifierItem(QObject *parent = nullptr);
    ~KAIChatNotificatifierItem() override;

private:
    void createTrayIcon();
};
