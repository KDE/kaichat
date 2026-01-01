/*
   SPDX-FileCopyrightText: 2020-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QWidget>

#include "libkaichatwidgets_private_export.h"

#include "config-kaichat.h"

#if HAVE_KUSERFEEDBACK
namespace KUserFeedback
{
class FeedbackConfigWidget;
}
#endif
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatConfigureUserFeedbackWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatConfigureUserFeedbackWidget(QWidget *parent = nullptr);
    ~KAIChatConfigureUserFeedbackWidget() override;

    void save();
    void load();
    void restoreToDefaults();

private:
#if HAVE_KUSERFEEDBACK
    KUserFeedback::FeedbackConfigWidget *const mUserFeedbackWidget;
#endif
};
