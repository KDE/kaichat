/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QString>
namespace CurrentDateTimeToolPluginUtils
{
enum DateTimeEnum : int8_t {
    Time = 0,
    Date,
    DateTime,
};
[[nodiscard]] QString convertDateTimeEnumToString(CurrentDateTimeToolPluginUtils::DateTimeEnum type);
};
