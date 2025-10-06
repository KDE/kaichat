/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "currentdatetimetoolpluginjob.h"
#include "currentdatetimetoolpluginutils.h"
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
    Q_EMIT toolInProgress(i18n("Get Current Date Time."));
    QString result;
    const QStringList lst = requiredArguments();
    for (const auto &arg : lst) {
        for (const auto &resultTool : std::as_const(mToolArguments)) {
            if (resultTool.keyTool == arg) {
                const QString value = resultTool.value;
                if (arg == "currentdatetime"_L1) {
                    const CurrentDateTimeToolPluginUtils::DateTimeEnum typeDateTime = CurrentDateTimeToolPluginUtils::convertStringToDateTimeEnum(value);
                    switch (typeDateTime) {
                    case CurrentDateTimeToolPluginUtils::DateTimeEnum::Time:
                        result = i18n("Current time is %1", QLocale().toString(QTime::currentTime()));
                        break;
                    case CurrentDateTimeToolPluginUtils::DateTimeEnum::Date:
                        result = i18n("Current date is %1", QLocale().toString(QDate::currentDate()));
                        break;
                    case CurrentDateTimeToolPluginUtils::DateTimeEnum::DateTime:
                        result = i18n("Current date time is %1", QLocale().toString(QDateTime::currentDateTime()));
                        break;
                    case CurrentDateTimeToolPluginUtils::DateTimeEnum::Unknown:
                        qCWarning(KAICHAT_CURRENTDATETIME_LOG) << "Invalid date time argument" << value;
                        break;
                    }
                }
            }
        }
    }

    qDebug() << " toolArguments " << toolArguments();
    Q_EMIT finished(result, mMessageUuid, mChatId, mToolIdentifier);
    deleteLater();
}

#include "moc_currentdatetimetoolpluginjob.cpp"
