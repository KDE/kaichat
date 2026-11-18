/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatwidgets_export.h"
#include <TextAutoGenerateText/TextAutoGenerateManager>
class QWidget;
namespace KAIChatUtils
{
LIBKAICHATWIDGETS_EXPORT void createQuickAsk(const TextAutoGenerateText::TextAutoGenerateManager::AskMessageInfo &info = {},
                                             TextAutoGenerateText::TextAutoGenerateManager *manager = nullptr,
                                             QWidget *parent = nullptr);
};
