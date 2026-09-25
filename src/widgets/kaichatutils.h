/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatwidgets_export.h"
class QWidget;
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
namespace KAIChatUtils
{
LIBKAICHATWIDGETS_EXPORT void createQuickAsk(TextAutoGenerateText::TextAutoGenerateManager *manager = nullptr, QWidget *parent = nullptr);
};
