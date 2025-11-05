/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once
#include "config-kaichat.h"
#include <QVariant>
#include <TextAutoGenerateText/TextAutoGenerateTextToolPlugin>
class CurrentDateTimeToolPlugin : public TextAutoGenerateText::TextAutoGenerateTextToolPlugin
{
    Q_OBJECT
public:
    explicit CurrentDateTimeToolPlugin(QObject *parent = nullptr, const QVariantList & = {});
    ~CurrentDateTimeToolPlugin() override;

    [[nodiscard]] QString displayName() const override;
    [[nodiscard]] QString description() const override;
#if HAVE_NEW_TOOLS_PLUGINS_SUPPORT
    [[nodiscard]] int order() const override;
#endif
    void showConfigureDialog(QWidget *parent) override;

#if HAVE_NEW_TOOLS_PLUGINS_SUPPORT
    [[nodiscard]] TextAutoGenerateText::TextAutoGenerateTextToolPluginJob *callTool() override;
#else
    void
    callTools(const QByteArray &chatId, const QByteArray &uuid, const QList<TextAutoGenerateText::TextAutoGenerateReply::ToolCallArgumentInfo> &info) override;
#endif
};
