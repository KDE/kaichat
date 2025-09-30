/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "currentdatetimetoolpluginjob.h"
#include "kaichat_currentdatetimeplugin_debug.h"
#include <KLocalizedString>
#include <QDateTime>
#include <QLocale>

using namespace Qt::Literals::StringLiterals;
CurrentDateTimeToolPluginJob::CurrentDateTimeToolPluginJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateTextToolPluginJob{parent}
{
}

CurrentDateTimeToolPluginJob::~CurrentDateTimeToolPluginJob() = default;

void CurrentDateTimeToolPluginJob::start()
{
    if (!canStart()) {
        qCWarning(KAICHAT_CURRENTDATETIME_LOG) << " Impossible to start CurrentDateTimeToolPluginJob" << *this;
        deleteLater();
        return;
    }
    qDebug() << " toolArguments " << toolArguments();
    Q_EMIT finished(i18n("Current Date Time is %1", QLocale().toString(QDateTime::currentDateTime())), mMessageUuid, mChatId, mToolIdentifier);
    deleteLater();
}

#include "moc_currentdatetimetoolpluginjob.cpp"
