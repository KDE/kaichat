/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "core/tools/textautogeneratetexttoolplugin.h"
#include <QVariant>
class ExampleTextToolPlugin : public TextAutoGenerateText::TextAutoGenerateTextToolPlugin
{
    Q_OBJECT
public:
    explicit ExampleTextToolPlugin(QObject *parent = nullptr, const QVariantList & = {});
    ~ExampleTextToolPlugin() override;

    void executeTool() override;
    [[nodiscard]] QString displayName() const override;
    [[nodiscard]] QString description() const override;

    void showConfigureDialog(QWidget *parent) override;

    void
    callTools(const QByteArray &chatId, const QByteArray &uuid, const QList<TextAutoGenerateText::TextAutoGenerateReply::ToolCallArgumentInfo> &info) override;
};
