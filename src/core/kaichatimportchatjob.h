/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "libkaichatcore_export.h"
#include <QObject>

class LIBKAICHATCORE_EXPORT KAIChatImportChatJob : public QObject
{
    Q_OBJECT
public:
    explicit KAIChatImportChatJob(QObject *parent = nullptr);
    ~KAIChatImportChatJob() override;

    [[nodiscard]] QString fileName() const;
    void setFileName(const QString &newFileName);

private:
    QString mFileName;
};
