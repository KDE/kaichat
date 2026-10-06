/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigurespeechtotextwidget.h"
#include "textautogeneratetext/textautogeneratetextglobalconfig.h"

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
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setEnableSpeechToText(mEnableSpeechToText->isChecked());
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->save();
    mSpeechToTextWidget->saveSettings();
}

void KAIChatConfigureSpeechToTextWidget::load()
{
    mSpeechToTextWidget->loadSettings();
    mEnableSpeechToText->setChecked(TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->enableSpeechToText());
    mSpeechToTextWidget->setEnabled(mEnableSpeechToText->isChecked());
}

void KAIChatConfigureSpeechToTextWidget::restoreToDefaults()
{
    const bool bUseDefaults = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(true);
    const bool enableSpeechToText = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->enableSpeechToText();
    mEnableSpeechToText->setChecked(enableSpeechToText);
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(bUseDefaults);
}

#include "moc_kaichatconfigurespeechtotextwidget.cpp"
