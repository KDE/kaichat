/*  This file is part of the KDE project
    SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "libkaichatwidgets_export.h"

/* Classes which are exported only for unit tests */
#ifdef BUILD_TESTING
#ifndef LIBKAICHATWIDGETS_TESTS_EXPORT
#define LIBKAICHATWIDGETS_TESTS_EXPORT LIBKAICHATWIDGETS_EXPORT
#endif
#else /* not compiling tests */
#define LIBKAICHATWIDGETS_TESTS_EXPORT
#endif
