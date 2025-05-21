/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "libkaichatcore_export.h"
#include <QObject>

class LIBKAICHATCORE_EXPORT KAIChatExportChatJob : public QObject
{
    Q_OBJECT
public:
    explicit KAIChatExportChatJob(QObject *parent = nullptr);
    ~KAIChatExportChatJob() override;
    [[nodiscard]] bool canStart() const;
    [[nodiscard]] QByteArray chatId() const;
    void setChatId(const QByteArray &newChatId);

    [[nodiscard]] QString fileName() const;
    void setFileName(const QString &newFileName);

private:
    QByteArray mChatId;
    QString mFileName;
};
