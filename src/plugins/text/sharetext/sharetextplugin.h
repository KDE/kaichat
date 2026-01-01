/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once
#include <TextAutoGenerateText/TextAutoGeneratePluginText>
class QObject;
#include <QVariant>

class ShareTextPlugin : public TextAutoGenerateText::TextAutoGeneratePluginText
{
    Q_OBJECT
public:
    explicit ShareTextPlugin(QObject *parent = nullptr, const QVariantList & = {});
    ~ShareTextPlugin() override;

    [[nodiscard]] TextAutoGenerateText::TextAutoGeneratePluginTextInterface *createInterface(QObject *parent) override;
    [[nodiscard]] int order() const override;
};
