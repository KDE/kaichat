/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureaccessibilitytabwidget.h"

KAIChatConfigureAccessibilityTabWidget::KAIChatConfigureAccessibilityTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    setTabBarAutoHide(true);
}

KAIChatConfigureAccessibilityTabWidget::~KAIChatConfigureAccessibilityTabWidget() = default;

#include "moc_kaichatconfigureaccessibilitytabwidget.cpp"
