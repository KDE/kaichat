/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigurespeechtotextwidget.h"
#include "kaichatglobalconfig.h"

#include <TextSpeechToText/SpeechToTextConfigureWidget>

#include <KLocalizedString>

#include <QCheckBox>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureSpeechToTextWidget::KAIChatConfigureSpeechToTextWidget(QWidget *parent)
    : QWidget{parent}
    , mSpeechToTextWidget(new TextSpeechToText::SpeechToTextConfigureWidget(this))
    , mEnableSpeechToText(new QCheckBox(i18nc("@option:check", "Enable Speech To Text"), this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    mEnableSpeechToText->setObjectName(u"mEnableSpeechToText"_s);
    mainLayout->addWidget(mEnableSpeechToText);

    mSpeechToTextWidget->setObjectName(u"mSpeechToTextWidget"_s);
    mainLayout->addWidget(mSpeechToTextWidget);

    connect(mEnableSpeechToText, &QCheckBox::toggled, mSpeechToTextWidget, &TextSpeechToText::SpeechToTextConfigureWidget::setEnabled);
}

KAIChatConfigureSpeechToTextWidget::~KAIChatConfigureSpeechToTextWidget() = default;

void KAIChatConfigureSpeechToTextWidget::save()
{
    KAIChatGlobalConfig::self()->setEnableSpeechToText(mEnableSpeechToText->isChecked());
    KAIChatGlobalConfig::self()->save();
    mSpeechToTextWidget->saveSettings();
}

void KAIChatConfigureSpeechToTextWidget::load()
{
    mSpeechToTextWidget->loadSettings();
    mEnableSpeechToText->setChecked(KAIChatGlobalConfig::self()->enableSpeechToText());
    mSpeechToTextWidget->setEnabled(mEnableSpeechToText->isChecked());
}

void KAIChatConfigureSpeechToTextWidget::restoreToDefaults()
{
    const bool bUseDefaults = KAIChatGlobalConfig::self()->useDefaults(true);
    const bool enableSpeechToText = KAIChatGlobalConfig::self()->enableSpeechToText();
    mEnableSpeechToText->setChecked(enableSpeechToText);
    KAIChatGlobalConfig::self()->useDefaults(bUseDefaults);
}

#include "moc_kaichatconfigurespeechtotextwidget.cpp"
