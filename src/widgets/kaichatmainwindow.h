/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
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
class KAIChatImportMenu;
class KAIChatChangeFontSizeMenu;
class QCommandLineParser;
class QLabel;
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
namespace TextAddonsWidgets
{
class VerifyNewVersionWidget;
}
#endif
namespace TextAutoGenerateText
{
class TextAutoGenerateMessage;
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
    LIBKAICHATWIDGETS_NO_EXPORT void slotImportDone(const QString &title, const QList<TextAutoGenerateText::TextAutoGenerateMessage> &msgs);
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
    LIBKAICHATWIDGETS_NO_EXPORT void updateActions();
    LIBKAICHATWIDGETS_NO_EXPORT void slotQuickAsk();
    LIBKAICHATWIDGETS_NO_EXPORT void disableActions();
    LIBKAICHATWIDGETS_NO_EXPORT void slotDownloadModelFinished(const QString &modelName);
    LIBKAICHATWIDGETS_NO_EXPORT void slotConfigureNotifications();
    LIBKAICHATWIDGETS_NO_EXPORT void setupStatusBar();
    LIBKAICHATWIDGETS_NO_EXPORT void slotStatusBarInfoChanged(const QString &str);
    LIBKAICHATWIDGETS_NO_EXPORT void slotImportInfoRequested();
    bool mReallyClose{false};
    KToggleAction *mShowMenuBarAction = nullptr;
    KHamburgerMenu *mHamburgerMenu = nullptr;
    KToggleFullScreenAction *mShowFullScreenAction = nullptr;
    KToggleAction *mShowArchivedAction = nullptr;
    KAIChatNotificatifierItem *mNotification = nullptr;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
    KAIChatCentralWidget *const mMainWidget;
    KAIChatExportMenu *mExportMenu = nullptr;
    KAIChatImportMenu *mImportMenu = nullptr;
    QAction *mShowQuickAskAction = nullptr;
    KAIChatChangeFontSizeMenu *mChangeFontSizeAction = nullptr;
    QLabel *mToolProgressInfo = nullptr;
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
    TextAddonsWidgets::VerifyNewVersionWidget *const mVerifyNewVersionWidget;
#endif
};
