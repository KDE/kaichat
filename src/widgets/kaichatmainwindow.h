/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "libkaichatwidgets_export.h"
#include <KXmlGuiWindow>
class KAIChatCentralWidget;
class KToggleAction;
class LIBKAICHATWIDGETS_EXPORT KAIChatMainWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    explicit KAIChatMainWindow(QWidget *parent = nullptr);
    ~KAIChatMainWindow() override;

private:
    LIBKAICHATWIDGETS_NO_EXPORT void readConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void setupActions();
    LIBKAICHATWIDGETS_NO_EXPORT void slotClose();
    LIBKAICHATWIDGETS_NO_EXPORT void slotConfigure();
    LIBKAICHATWIDGETS_NO_EXPORT void slotToggleMenubar(bool dontShowWarning);
    KAIChatCentralWidget *const mMainWidget;
    bool mReallyClose{false};
    KToggleAction *mShowMenuBarAction = nullptr;
};
