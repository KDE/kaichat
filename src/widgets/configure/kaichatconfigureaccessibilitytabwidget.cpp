/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureaccessibilitytabwidget.h"
#include "configure/kaichatconfigureaccessibilitywidget.h"
#include <KLocalizedString>
#if HAVE_SPEECH_TO_TEXT
#include <TextSpeechToText/SpeechToTextConfigureWidget>
#endif
KAIChatConfigureAccessibilityTabWidget::KAIChatConfigureAccessibilityTabWidget(QWidget *parent)
    : QTabWidget(parent)
#if HAVE_TEXT_TO_SPEECH
    , mConfigureAccessibilityWidget(new KAIChatConfigureAccessibilityWidget(this))
#endif
#if HAVE_SPEECH_TO_TEXT
    , mConfigureSpeechToTextWidget(new TextSpeechToText::SpeechToTextConfigureWidget(this))
#endif
{
    setTabBarAutoHide(true);
#if HAVE_TEXT_TO_SPEECH
    addTab(mConfigureAccessibilityWidget, i18n("Text to Speech"));
#endif
#if HAVE_SPEECH_TO_TEXT
    addTab(mConfigureSpeechToTextWidget, i18n("Speech to Text"));
#endif
}

KAIChatConfigureAccessibilityTabWidget::~KAIChatConfigureAccessibilityTabWidget() = default;

void KAIChatConfigureAccessibilityTabWidget::save()
{
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->save();
#endif
#if HAVE_SPEECH_TO_TEXT
    mConfigureSpeechToTextWidget->saveSettings();
#endif
}

void KAIChatConfigureAccessibilityTabWidget::load()
{
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->load();
#endif
#if HAVE_SPEECH_TO_TEXT
    mConfigureSpeechToTextWidget->loadSettings();
#endif
}

void KAIChatConfigureAccessibilityTabWidget::restoreToDefaults()
{
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->restoreToDefaults();
#endif
#if HAVE_SPEECH_TO_TEXT
    // TODO mConfigureSpeechToTextWidget->restoreToDefaults();
#endif
}

#include "moc_kaichatconfigureaccessibilitytabwidget.cpp"
