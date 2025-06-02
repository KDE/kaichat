/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"
#include <QDebug>
#include <QObject>
#include <TextAutoGenerateText/TextAutoGenerateMessage>

class LIBKAICHATCORE_EXPORT KAIChatExportChatAsBaseJob : public QObject
{
    Q_OBJECT
public:
    struct LIBKAICHATCORE_EXPORT ExportChatInfo {
        QString filename;
        QString chatTitle;
        QList<TextAutoGenerateText::TextAutoGenerateMessage> listMessages;
        [[nodiscard]] bool isValid() const;
    };

    explicit KAIChatExportChatAsBaseJob(QObject *parent = nullptr);
    ~KAIChatExportChatAsBaseJob() override;

    [[nodiscard]] ExportChatInfo info() const;
    void setInfo(const ExportChatInfo &newInfo);

    [[nodiscard]] bool canStart() const;
    void start();

Q_SIGNALS:
    void exportDone();

protected:
    virtual void exportChat() = 0;
    ExportChatInfo mInfo;
};
Q_DECLARE_TYPEINFO(KAIChatExportChatAsBaseJob::ExportChatInfo, Q_RELOCATABLE_TYPE);
LIBKAICHATCORE_EXPORT QDebug operator<<(QDebug d, const KAIChatExportChatAsBaseJob::ExportChatInfo &t);
