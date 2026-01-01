/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QVariant>
#include <TextAutoGenerateText/TextAutoGeneratePluginText>

class WebShortcutTextPlugin : public TextAutoGenerateText::TextAutoGeneratePluginText
{
    Q_OBJECT
public:
    explicit WebShortcutTextPlugin(QObject *parent = nullptr, const QVariantList & = {});
    ~WebShortcutTextPlugin() override;

    [[nodiscard]] TextAutoGenerateText::TextAutoGeneratePluginTextInterface *createInterface(QObject *parent) override;

    [[nodiscard]] int order() const override;
};
