/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "currentdatetimetoolpluginjob.h"
#include "kaichat_currentdatetimeplugin_debug.h"

using namespace Qt::Literals::StringLiterals;
CurrentDateTimeToolPluginJob::CurrentDateTimeToolPluginJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateTextToolPluginJob{parent}
{
}

CurrentDateTimeToolPluginJob::~CurrentDateTimeToolPluginJob() = default;

void CurrentDateTimeToolPluginJob::start()
{
    qDebug() << " void CurrentDateTimeToolPluginJob::start() ";
    if (!canStart()) {
        qCWarning(KAICHAT_CURRENTDATETIME_LOG) << " Impossible to start CurrentDateTimeToolPluginJob" << *this;
        deleteLater();
        return;
    }
    // TODO Need to implement job
    Q_EMIT finished(u"Temperature is 35°"_s, mMessageUuid, mChatId, mToolIdentifier);
    deleteLater();
}

#include "moc_currentdatetimetoolpluginjob.cpp"
