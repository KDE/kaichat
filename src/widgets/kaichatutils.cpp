/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatutils.h"
#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateQuickAskDialog>

void KAIChatUtils::createQuickAsk(QWidget *parent)
{
    auto *manager = new TextAutoGenerateText::TextAutoGenerateManager;
    auto quickAskdialog = new TextAutoGenerateText::TextAutoGenerateQuickAskDialog(manager, parent);
    manager->setParent(quickAskdialog);
    quickAskdialog->exec();
    delete quickAskdialog;
}
