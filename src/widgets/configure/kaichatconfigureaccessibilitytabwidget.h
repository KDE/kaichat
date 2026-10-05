/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once
#include "config-kaichat.h"
#include "libkaichatwidgets_private_export.h"
#include <QTabWidget>
class KAIChatConfigureAccessibilityWidget;
class KAIChatConfigureSpeechToTextWidget;
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatConfigureAccessibilityTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureAccessibilityTabWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureAccessibilityTabWidget() override;

    void save();
    void load();
    void restoreToDefaults();

private:
#if HAVE_TEXT_TO_SPEECH
    KAIChatConfigureAccessibilityWidget *const mConfigureAccessibilityWidget;
#endif
#if HAVE_SPEECH_TO_TEXT
    KAIChatConfigureSpeechToTextWidget *const mConfigureSpeechToTextWidget;
#endif
};
