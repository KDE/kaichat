/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <KCModule>

namespace TextAutoGenerateTextMcpProtocolWidgets
{
class McpServerWidget;
}

namespace TextAutoGenerateText
{
class TextAutoGenerateTextInstancesManagerWidget;
}
class KCMAutoGenerateText : public KCModule
{
    Q_OBJECT
public:
    explicit KCMAutoGenerateText(QObject *parent, const KPluginMetaData &data);

public Q_SLOTS:
    void load() override;
    void save() override;
    void defaults() override;

private:
    TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget *mManagerWidget = nullptr;
    TextAutoGenerateTextMcpProtocolWidgets::McpServerWidget *mMcpProtocolWidget = nullptr;
};
