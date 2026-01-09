/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include <KActionMenu>
#include <TextAutoGenerateText/TextAutoGenerateImportChatBaseJob>
class KAIChatImportMenu : public KActionMenu
{
    Q_OBJECT
public:
    explicit KAIChatImportMenu(QObject *parent = nullptr);
    ~KAIChatImportMenu() override;

    void setImportChatInfo(const TextAutoGenerateText::TextAutoGenerateImportChatBaseJob::ImportChatInfo &newInfo);

Q_SIGNALS:
    void importRequested();

private:
    enum class ConvertFromType : uint8_t {
        Unknown = 0,
        Json,
    };
    ConvertFromType mConvertFromType = ConvertFromType::Unknown;
};
