/*
   SPDX-FileCopyrightText: 2022-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureaccessibilitywidget.h"
#include "kaichatglobalconfig.h"
#include <TextEditTextToSpeech/TextToSpeechConfigWidget>

#include <KLocalizedString>

#include <QCheckBox>
#include <QShowEvent>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureAccessibilityWidget::KAIChatConfigureAccessibilityWidget(QWidget *parent)
    : QWidget{parent}
    , mTextToSpeechWidget(new TextEditTextToSpeech::TextToSpeechConfigWidget(this))
    , mEnableTextToSpeech(new QCheckBox(i18nc("@option:check", "Enable Text To Speech"), this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mEnableTextToSpeech->setObjectName(u"mEnableTextToSpeech"_s);
    mainLayout->addWidget(mEnableTextToSpeech);

    mTextToSpeechWidget->setObjectName(u"mTextToSpeechWidget"_s);
    mainLayout->addWidget(mTextToSpeechWidget);

    connect(mEnableTextToSpeech, &QCheckBox::toggled, mTextToSpeechWidget, &TextEditTextToSpeech::TextToSpeechConfigWidget::setEnabled);
}

KAIChatConfigureAccessibilityWidget::~KAIChatConfigureAccessibilityWidget() = default;

void KAIChatConfigureAccessibilityWidget::save()
{
    if (mWasInitialized) {
        KAIChatGlobalConfig::self()->setEnableTextToSpeech(mEnableTextToSpeech->isChecked());
        KAIChatGlobalConfig::self()->save();
        mTextToSpeechWidget->writeConfig();
    }
}

void KAIChatConfigureAccessibilityWidget::load()
{
    mTextToSpeechWidget->initializeSettings();
    mEnableTextToSpeech->setChecked(KAIChatGlobalConfig::self()->enableTextToSpeech());
    mTextToSpeechWidget->setEnabled(mEnableTextToSpeech->isChecked());
}

void KAIChatConfigureAccessibilityWidget::restoreToDefaults()
{
    mTextToSpeechWidget->restoreDefaults();
    const bool bUseDefaults = KAIChatGlobalConfig::self()->useDefaults(true);
    const bool enableTextToSpeech = KAIChatGlobalConfig::self()->enableTextToSpeech();
    mEnableTextToSpeech->setChecked(enableTextToSpeech);
    KAIChatGlobalConfig::self()->useDefaults(bUseDefaults);
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
