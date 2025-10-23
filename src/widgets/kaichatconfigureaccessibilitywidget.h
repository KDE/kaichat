/*
   SPDX-FileCopyrightText: 2022-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>

#include <QWidget>
namespace TextEditTextToSpeech
{
class TextToSpeechConfigWidget;
}

class KAIChatConfigureAccessibilityWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureAccessibilityWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureAccessibilityWidget() override;

    void save();
    void load();
    void restoreToDefaults();

protected:
    void showEvent(QShowEvent *event) override;

private:
    TextEditTextToSpeech::TextToSpeechConfigWidget *const mTextToSpeechWidget;
    bool mWasInitialized = false;
};
