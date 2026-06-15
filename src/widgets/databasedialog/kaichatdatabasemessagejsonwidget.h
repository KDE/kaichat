/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once

#include <QWidget>
class JsonPlainTextEditWidget;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class KAIChatDatabaseMessageJsonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatDatabaseMessageJsonWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatDatabaseMessageJsonWidget() override;

    void loadJsonMessages(const QString &chatId);

private:
    JsonPlainTextEditWidget *const mJsonPlainTextEditWidget;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
};
