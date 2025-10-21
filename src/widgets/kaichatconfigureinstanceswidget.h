/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once

#include <QWidget>
namespace TextAutoGenerateText
{
class TextAutoGenerateTextInstancesManagerWidget;
class TextAutoGenerateManager;
}
class KAIChatConfigureInstancesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureInstancesWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatConfigureInstancesWidget() override;
    void save();
    void load();
    void restoreToDefaults();

private:
    TextAutoGenerateText::TextAutoGenerateTextInstancesManagerWidget *const mInstancesManagerWidget;
};
