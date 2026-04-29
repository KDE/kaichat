/*
   SPDX-FileCopyrightText: 2020-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureuserfeedbackwidget.h"

#include <QVBoxLayout>

#include "userfeedback/userfeedbackmanager.h"
#include <KUserFeedback/FeedbackConfigWidget>
#include <KUserFeedback/Provider>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureUserFeedbackWidget::KAIChatConfigureUserFeedbackWidget(QWidget *parent)
    : QWidget(parent)
    , mUserFeedbackWidget(new KUserFeedback::FeedbackConfigWidget(this))
{
    auto userFeedBackLayout = new QVBoxLayout(this);
    userFeedBackLayout->setObjectName(u"userFeedBackLayout"_s);
    userFeedBackLayout->setContentsMargins({});
    mUserFeedbackWidget->setObjectName(u"mUserFeedbackWidget"_s);
    userFeedBackLayout->addWidget(mUserFeedbackWidget);
}

KAIChatConfigureUserFeedbackWidget::~KAIChatConfigureUserFeedbackWidget() = default;

void KAIChatConfigureUserFeedbackWidget::save()
{
    // set current active mode + write back the config for future starts
    UserFeedBackManager::self()->userFeedbackProvider()->setTelemetryMode(mUserFeedbackWidget->telemetryMode());
    UserFeedBackManager::self()->userFeedbackProvider()->setSurveyInterval(mUserFeedbackWidget->surveyInterval());
}

void KAIChatConfigureUserFeedbackWidget::load()
{
    mUserFeedbackWidget->setFeedbackProvider(UserFeedBackManager::self()->userFeedbackProvider());
}

void KAIChatConfigureUserFeedbackWidget::restoreToDefaults()
{
    mUserFeedbackWidget->setFeedbackProvider(UserFeedBackManager::self()->userFeedbackProvider());
}

#include "moc_kaichatconfigureuserfeedbackwidget.cpp"
