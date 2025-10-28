/*
   SPDX-FileCopyrightText: 2022-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureaccessibilitywidget.h"
#include "textautogeneratetext/textautogeneratetextglobalconfig.h"

#include <TextEditTextToSpeech/TextToSpeech>
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
        TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setEnableTextToSpeech(mEnableTextToSpeech->isChecked());
        TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->save();
        mTextToSpeechWidget->writeConfig();
        TextEditTextToSpeech::TextToSpeech::self()->reloadSettings();
    }
}

void KAIChatConfigureAccessibilityWidget::load()
{
    mTextToSpeechWidget->initializeSettings();
    mEnableTextToSpeech->setChecked(TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->enableTextToSpeech());
    mTextToSpeechWidget->setEnabled(mEnableTextToSpeech->isChecked());
}

void KAIChatConfigureAccessibilityWidget::restoreToDefaults()
{
    mTextToSpeechWidget->restoreDefaults();
    const bool bUseDefaults = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(true);
    const bool enableTextToSpeech = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->enableTextToSpeech();
    mEnableTextToSpeech->setChecked(enableTextToSpeech);
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(bUseDefaults);
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
