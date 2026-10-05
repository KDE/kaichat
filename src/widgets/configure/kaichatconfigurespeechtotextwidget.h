/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QWidget>
namespace TextSpeechToText
{
class SpeechToTextConfigureWidget;
}
class QCheckBox;
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatConfigureSpeechToTextWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureSpeechToTextWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureSpeechToTextWidget() override;

    void save();
    void load();
    void restoreToDefaults();

private:
    TextSpeechToText::SpeechToTextConfigureWidget *const mSpeechToTextWidget;
    QCheckBox *const mEnableSpeechToText;
};
