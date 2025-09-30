/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "currentdatetimetoolpluginutils.h"
#include "kaichat_currentdatetimeplugin_debug.h"

using namespace Qt::Literals::StringLiterals;
QString CurrentDateTimeToolPluginUtils::convertDateTimeEnumToString(DateTimeEnum type)
{
    switch (type) {
    case Time:
        return u"time"_s;
    case Date:
        return u"date"_s;
    case DateTime:
        return u"date and time"_s;
    case Unknown:
        break;
    }
    Q_UNREACHABLE();
    return {};
}

CurrentDateTimeToolPluginUtils::DateTimeEnum CurrentDateTimeToolPluginUtils::convertStringToDateTimeEnum(const QString &str)
{
    if (str == "time"_L1) {
        return CurrentDateTimeToolPluginUtils::DateTimeEnum::Time;
    } else if (str == "date"_L1) {
        return CurrentDateTimeToolPluginUtils::DateTimeEnum::Date;
    } else if (str == "date and time"_L1) {
        return CurrentDateTimeToolPluginUtils::DateTimeEnum::DateTime;
    } else {
        qCWarning(KAICHAT_CURRENTDATETIME_LOG) << "Invalid date time type:" << str;
        return CurrentDateTimeToolPluginUtils::DateTimeEnum::Unknown;
    }
    return CurrentDateTimeToolPluginUtils::DateTimeEnum::Unknown;
}
