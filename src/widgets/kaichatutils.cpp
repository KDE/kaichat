/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#include "kaichatutils.h"
#include "textautogeneratetext_version.h"
#include <TextAutoGenerateText/TextAutoGenerateQuickAskDialog>

void KAIChatUtils::createQuickAsk(const TextAutoGenerateText::TextAutoGenerateManager::AskMessageInfo &info,
                                  TextAutoGenerateText::TextAutoGenerateManager *manager,
                                  QWidget *parent)
{
    auto quickManager = manager ? manager : new TextAutoGenerateText::TextAutoGenerateManager;
    auto quickAskdialog = new TextAutoGenerateText::TextAutoGenerateQuickAskDialog(quickManager, parent);
    if (!manager) {
        quickManager->setParent(quickAskdialog);
    }
    if (info.isValid()) {
#if TEXTAUTOGENERATETEXT_VERSION >= QT_VERSION_CHECK(2, 3, 43)
        if (info.message.isEmpty() && !info.attachments.isEmpty()) {
            quickAskdialog->prepare(info);
        } else {
            quickAskdialog->ask(info);
        }
#else
        quickAskdialog->ask(info);
#endif
    }
    quickAskdialog->exec();
    delete quickAskdialog;
}
