/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QString>
namespace CurrentDateTimeToolPluginUtils
{
enum DateTimeEnum : int8_t {
    Unknown = 0,
    Time,
    Date,
    DateTime,
};
[[nodiscard]] QString convertDateTimeEnumToString(CurrentDateTimeToolPluginUtils::DateTimeEnum type);
[[nodiscard]] CurrentDateTimeToolPluginUtils::DateTimeEnum convertStringToDateTimeEnum(const QString &str);
[[nodiscard]] QString currentDateTimePropertyName();
};
