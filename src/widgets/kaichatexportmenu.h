/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include <KActionMenu>
#include <TextAutoGenerateText/TextAutoGenerateExportChatBaseJob>
class KAIChatExportMenu : public KActionMenu
{
    Q_OBJECT
public:
    explicit KAIChatExportMenu(QObject *parent = nullptr);
    ~KAIChatExportMenu() override;

    void setExportChatInfo(const TextAutoGenerateText::TextAutoGenerateExportChatBaseJob::ExportChatInfo &newInfo);
Q_SIGNALS:
    void exportInfoRequested();

private:
    enum class ConvertToType : uint8_t {
        Unknown = 0,
        Json,
        Markdown,
        Text,
    };
    void convertChat(const TextAutoGenerateText::TextAutoGenerateExportChatBaseJob::ExportChatInfo &newInfo);
    ConvertToType mConvertToType = ConvertToType::Unknown;
};
