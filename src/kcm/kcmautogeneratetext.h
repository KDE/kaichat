/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <KCModule>

class KCMAutoGenerateText : public KCModule
{
    Q_OBJECT
public:
    explicit KCMAutoGenerateText(QObject *parent, const KPluginMetaData &data);
};
