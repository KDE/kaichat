/*
   SPDX-FileCopyrightText: 2020-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureuserfeedbackwidget.h"

#include <QVBoxLayout>

#if HAVE_KUSERFEEDBACK
#include "userfeedback/userfeedbackmanager.h"
#include <KUserFeedback/FeedbackConfigWidget>
#include <KUserFeedback/Provider>
#endif

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureUserFeedbackWidget::KAIChatConfigureUserFeedbackWidget(QWidget *parent)
    : QWidget(parent)
#if HAVE_KUSERFEEDBACK
    , mUserFeedbackWidget(new KUserFeedback::FeedbackConfigWidget(this))
#endif
{
    auto userFeedBackLayout = new QVBoxLayout(this);
    userFeedBackLayout->setObjectName(u"userFeedBackLayout"_s);
    userFeedBackLayout->setContentsMargins({});
#if HAVE_KUSERFEEDBACK
    mUserFeedbackWidget->setObjectName(u"mUserFeedbackWidget"_s);
    userFeedBackLayout->addWidget(mUserFeedbackWidget);
#endif
}

KAIChatConfigureUserFeedbackWidget::~KAIChatConfigureUserFeedbackWidget() = default;

void KAIChatConfigureUserFeedbackWidget::save()
{
#if HAVE_KUSERFEEDBACK
    // set current active mode + write back the config for future starts
    UserFeedBackManager::self()->userFeedbackProvider()->setTelemetryMode(mUserFeedbackWidget->telemetryMode());
    UserFeedBackManager::self()->userFeedbackProvider()->setSurveyInterval(mUserFeedbackWidget->surveyInterval());
#endif
}

void KAIChatConfigureUserFeedbackWidget::load()
{
#if HAVE_KUSERFEEDBACK
    mUserFeedbackWidget->setFeedbackProvider(UserFeedBackManager::self()->userFeedbackProvider());
#endif
}

void KAIChatConfigureUserFeedbackWidget::restoreToDefaults()
{
#if HAVE_KUSERFEEDBACK
    // TODO
#endif
}

#include "moc_kaichatconfigureuserfeedbackwidget.cpp"
