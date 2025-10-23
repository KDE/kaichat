/*
   SPDX-FileCopyrightText: 2022-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureaccessibilitywidget.h"
using namespace Qt::Literals::StringLiterals;

#include <TextEditTextToSpeech/TextToSpeechConfigWidget>

#include <QShowEvent>
#include <QVBoxLayout>

KAIChatConfigureAccessibilityWidget::KAIChatConfigureAccessibilityWidget(QWidget *parent)
    : QWidget{parent}
    , mTextToSpeechWidget(new TextEditTextToSpeech::TextToSpeechConfigWidget(this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mTextToSpeechWidget->setObjectName(u"mTextToSpeechWidget"_s);
    mainLayout->addWidget(mTextToSpeechWidget);
}

KAIChatConfigureAccessibilityWidget::~KAIChatConfigureAccessibilityWidget() = default;

void KAIChatConfigureAccessibilityWidget::save()
{
    if (mWasInitialized) {
        mTextToSpeechWidget->writeConfig();
    }
}

void KAIChatConfigureAccessibilityWidget::load()
{
    mTextToSpeechWidget->initializeSettings();
}

void KAIChatConfigureAccessibilityWidget::restoreToDefaults()
{
    mTextToSpeechWidget->restoreDefaults();
}

void KAIChatConfigureAccessibilityWidget::showEvent(QShowEvent *event)
{
    if (!event->spontaneous() && !mWasInitialized) {
        mWasInitialized = true;
        mTextToSpeechWidget->readConfig();
    }
    QWidget::showEvent(event);
}

#include "moc_kaichatconfigureaccessibilitywidget.cpp"
