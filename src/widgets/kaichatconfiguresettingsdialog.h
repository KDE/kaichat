/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "libkaichatwidgets_private_export.h"
#include <KPageDialog>
class KAIChatConfigureGeneralWidget;
class KAIChatConfigureInstancesWidget;
class KAIChatConfigureFontWidget;
class KAIChatConfigureSpellCheckingWidget;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
class TextAutoGenerateTextConfigurePluginsWidget;
}
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatConfigureSettingsDialog : public KPageDialog
{
    Q_OBJECT
public:
    explicit KAIChatConfigureSettingsDialog(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent = nullptr);
    ~KAIChatConfigureSettingsDialog() override;

private:
    LIBKAICHATWIDGETS_NO_EXPORT void readConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void writeConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void slotAccepted();
    LIBKAICHATWIDGETS_NO_EXPORT void load();
    KAIChatConfigureGeneralWidget *const mConfigureGeneralWidget;
    KAIChatConfigureInstancesWidget *const mInstancesManagerWidget;
    TextAutoGenerateText::TextAutoGenerateTextConfigurePluginsWidget *const mConfigurePluginsWidget;
    KAIChatConfigureFontWidget *const mConfigureFontWidget;
    KAIChatConfigureSpellCheckingWidget *const mConfigureSpellCheckingWidget;
};
