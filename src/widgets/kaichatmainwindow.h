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
class KHamburgerMenu;
class KToggleFullScreenAction;
class KAIChatNotificatifierItem;
class KAIChatExportMenu;
class KAIChatChangeFontSizeMenu;
class QCommandLineParser;
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
class VerifyNewVersionWidgetAction;
#endif
namespace TextAutoGenerateText
{
class TextAutoGenerateManager;
}
class LIBKAICHATWIDGETS_EXPORT KAIChatMainWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    explicit KAIChatMainWindow(QWidget *parent = nullptr);
    ~KAIChatMainWindow() override;

    void slotActivateRequested(const QStringList &arguments, const QString &workingDirectory);

    void parseCommandLine(QCommandLineParser *parser);

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotShowArchive(bool checked);
    LIBKAICHATWIDGETS_NO_EXPORT void readConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void setupActions();
    LIBKAICHATWIDGETS_NO_EXPORT void slotClose();
    LIBKAICHATWIDGETS_NO_EXPORT void slotConfigure();
    LIBKAICHATWIDGETS_NO_EXPORT void slotToggleMenubar(bool dontShowWarning);
    LIBKAICHATWIDGETS_NO_EXPORT void updateHamburgerMenu();
    LIBKAICHATWIDGETS_NO_EXPORT void slotFullScreen(bool t);
    LIBKAICHATWIDGETS_NO_EXPORT void slotSearchText();
    LIBKAICHATWIDGETS_NO_EXPORT void createSystemTray();
    LIBKAICHATWIDGETS_NO_EXPORT void slotExportInfoRequested();
    LIBKAICHATWIDGETS_NO_EXPORT void slotWhatsNew();
    LIBKAICHATWIDGETS_NO_EXPORT void updateActions(bool enabled);
    LIBKAICHATWIDGETS_NO_EXPORT void slotQuickAsk();
    bool mReallyClose{false};
    KToggleAction *mShowMenuBarAction = nullptr;
    KHamburgerMenu *mHamburgerMenu = nullptr;
    KToggleFullScreenAction *mShowFullScreenAction = nullptr;
    KToggleAction *mShowArchivedAction = nullptr;
    KAIChatNotificatifierItem *mNotification = nullptr;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
    KAIChatCentralWidget *const mMainWidget;
    KAIChatExportMenu *mExportMenu = nullptr;
    QAction *mShowQuickAskAction = nullptr;
    KAIChatChangeFontSizeMenu *mChangeFontSizeAction = nullptr;
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
    VerifyNewVersionWidgetAction *const mVerifyNewVersionWidgetAction;
#endif
};
