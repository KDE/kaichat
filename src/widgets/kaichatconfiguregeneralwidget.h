/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include <QWidget>
class QCheckBox;
namespace TextAutoGenerateText
{
class TextAutoGenerateTextConfigurePromptWidget;
class TextAutoGenerateManager;
}
class KAIChatConfigureGeneralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureGeneralWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatConfigureGeneralWidget() override;

    void save();
    void load();
    void restoreToDefaults();

private:
    QCheckBox *const mEnableSystemTray;
    TextAutoGenerateText::TextAutoGenerateTextConfigurePromptWidget *const mConfigurePromptWidget;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
};
