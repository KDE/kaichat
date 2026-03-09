/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatadaptor.h"
#include <QApplication>

KAIChatAdaptor::KAIChatAdaptor()
    : QDBusAbstractAdaptor(qApp)
{
}
