/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureaccessibilitytabwidget.h"
#include "configure/kaichatconfigureaccessibilitywidget.h"
#include <KLocalizedString>

KAIChatConfigureAccessibilityTabWidget::KAIChatConfigureAccessibilityTabWidget(QWidget *parent)
    : QTabWidget(parent)
#if HAVE_TEXT_TO_SPEECH
    , mConfigureAccessibilityWidget(new KAIChatConfigureAccessibilityWidget(this))
#endif
{
    setTabBarAutoHide(true);
    addTab(mConfigureAccessibilityWidget, i18n("Text to Speech"));
}

KAIChatConfigureAccessibilityTabWidget::~KAIChatConfigureAccessibilityTabWidget() = default;

void KAIChatConfigureAccessibilityTabWidget::save()
{
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->save();
#endif
}

void KAIChatConfigureAccessibilityTabWidget::load()
{
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->load();
#endif
}

void KAIChatConfigureAccessibilityTabWidget::restoreToDefaults()
{
#if HAVE_TEXT_TO_SPEECH
    mConfigureAccessibilityWidget->restoreToDefaults();
#endif
}

#include "moc_kaichatconfigureaccessibilitytabwidget.cpp"
