/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "userfeedbackmanager.h"
#include "kaichatuserfeedbackprovider.h"

UserFeedBackManager::UserFeedBackManager()
    : mUserFeedbackProvider(new KAIChatUserFeedbackProvider())
{
}

UserFeedBackManager::~UserFeedBackManager()
{
    delete mUserFeedbackProvider;
}

UserFeedBackManager *UserFeedBackManager::self()
{
    static UserFeedBackManager s_self;
    return &s_self;
}

KUserFeedback::Provider *UserFeedBackManager::userFeedbackProvider() const
{
    return mUserFeedbackProvider;
}
