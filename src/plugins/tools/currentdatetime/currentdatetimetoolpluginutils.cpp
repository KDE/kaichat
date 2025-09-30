/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "currentdatetimetoolpluginutils.h"
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
    }
    Q_UNREACHABLE();
    return {};
}
