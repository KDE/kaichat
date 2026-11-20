/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "config-kaichat.h"
#include "libkaichatwidgets_private_export.h"
#include "textautogeneratetext_version.h"
#include <KPageDialog>
class KAIChatConfigureGeneralWidget;
class KAIChatConfigureInstancesWidget;
class KAIChatConfigureFontWidget;
class KAIChatConfigureSpellCheckingWidget;
class KAIChatConfigureUserFeedbackWidget;
class KAIChatConfigureMcpServersWidget;
class KAIChatConfigureRetentionWidget;
class KAIChatConfigurePrivacyWidget;
class KAIChatConfigureAccessibilityTabWidget;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
class TextAutoGenerateTextConfigurePluginsWidget;
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 3, 44)
class TextAutoGenerateTextConfigurePromptsAgentsWidget;
#endif
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
    LIBKAICHATWIDGETS_NO_EXPORT void slotRestoreDefaults();
    KAIChatConfigureGeneralWidget *const mConfigureGeneralWidget;
    KAIChatConfigureInstancesWidget *const mInstancesManagerWidget;
    TextAutoGenerateText::TextAutoGenerateTextConfigurePluginsWidget *const mConfigurePluginsWidget;
    KAIChatConfigureFontWidget *const mConfigureFontWidget;
    KAIChatConfigureSpellCheckingWidget *const mConfigureSpellCheckingWidget;
    KAIChatConfigureRetentionWidget *const mConfigureRetentionWidget;
    KAIChatConfigurePrivacyWidget *const mConfigurePrivacyWidget;
    KAIChatConfigureAccessibilityTabWidget *const mConfigureAccessibilityWidget;
    KPageWidgetItem *mConfigureTextToSpeechWidgetPage = nullptr;
#if HAVE_KUSERFEEDBACK
    KPageWidgetItem *mConfigureUserFeedBackWidgetPage = nullptr;
    KAIChatConfigureUserFeedbackWidget *const mConfigureUserFeedBackWidget = nullptr;
#endif
    KPageWidgetItem *mConfigureGeneralWidgetPage = nullptr;
    KPageWidgetItem *mConfigureFontWidgetPage = nullptr;
    KPageWidgetItem *mConfigureInstancesWidgetPage = nullptr;
    KPageWidgetItem *mConfigureSpellCheckWidgetPage = nullptr;
    KPageWidgetItem *mConfigurePluginsWidgetPage = nullptr;
    KAIChatConfigureMcpServersWidget *const mConfigureMcpServersWidget;
    KPageWidgetItem *mConfigureMcpServersWidgetPage = nullptr;
    KPageWidgetItem *mConfigureRetentionWidgetPage = nullptr;
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 3, 44)
    TextAutoGenerateText::TextAutoGenerateTextConfigurePromptsAgentsWidget *const mConfigurePromptsAgentsWidget;
    KPageWidgetItem *mConfigurePromptsAgentsWidgetPage = nullptr;
#endif
};
