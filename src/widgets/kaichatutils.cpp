/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatutils.h"
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateQuickAskDialog>

void KAIChatUtils::createQuickAsk(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
{
    auto quickManager = manager ? manager : new TextAutoGenerateText::TextAutoGenerateManager;
    auto quickAskdialog = new TextAutoGenerateText::TextAutoGenerateQuickAskDialog(quickManager, parent);
    if (!manager) {
        quickManager->setParent(quickAskdialog);
    }
    quickAskdialog->exec();
    delete quickAskdialog;
}
