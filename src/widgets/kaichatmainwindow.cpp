/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatmainwindow.h"

#include "kaichatcentralwidget.h"
#include "kaichatglobalconfig.h"

#include <KActionCollection>
#include <KConfigGroup>
#include <KHamburgerMenu>
#include <KLocalizedString>
#include <KMessageBox>
#include <KSharedConfig>
#include <KStandardAction>
#include <KStandardActions>
#include <KToggleAction>
#include <KToggleFullScreenAction>
#include <KToolBar>
#include <KWindowSystem>
#include <QCommandLineParser>
#include <QFontDatabase>
#include <QMenuBar>
namespace
{
static const char myKAIChatMainWindowGroupName[] = "KAIChatMainWindow";
}
using namespace Qt::Literals::StringLiterals;
KAIChatMainWindow::KAIChatMainWindow(QWidget *parent)
    : KXmlGuiWindow(parent)
    , mMainWidget(new KAIChatCentralWidget(this))
{
    mMainWidget->setObjectName(QStringLiteral("mMainWidget"));
    setCentralWidget(mMainWidget);
    setupActions();
    // TODO setupStatusBar();
    setupGUI();
    readConfig();
    mShowMenuBarAction->setChecked(KAIChatGlobalConfig::self()->showMenuBar());
    slotToggleMenubar(true);
}

KAIChatMainWindow::~KAIChatMainWindow()
{
    KSharedConfig::Ptr config = KSharedConfig::openConfig();
    KConfigGroup group = config->group(QLatin1StringView(myKAIChatMainWindowGroupName));
    group.writeEntry("Size", size());
}

void KAIChatMainWindow::readConfig()
{
    KSharedConfig::Ptr config = KSharedConfig::openConfig();
    KConfigGroup group = KConfigGroup(config, QLatin1StringView(myKAIChatMainWindowGroupName));
    const QSize sizeDialog = group.readEntry("Size", QSize(800, 600));
    if (sizeDialog.isValid()) {
        resize(sizeDialog);
    }
}

void KAIChatMainWindow::setupActions()
{
    KActionCollection *ac = actionCollection();

    mShowMenuBarAction = KStandardAction::showMenubar(this, &KAIChatMainWindow::slotToggleMenubar, ac);

    mShowArchivedAction = new KToggleAction(i18nc("@action", "Show Archive"), this);

    connect(mShowArchivedAction, &KToggleAction::triggered, this, &KAIChatMainWindow::slotShowArchive);
    ac->addAction(QStringLiteral("show_archive"), mShowArchivedAction);

    KStandardActions::quit(this, &KAIChatMainWindow::slotClose, ac);
    KStandardActions::preferences(this, &KAIChatMainWindow::slotConfigure, ac);
    // KStandardActions::configureNotifications(this, &RuqolaMainWindow::slotConfigureNotifications, ac);

    mShowFullScreenAction = KStandardAction::fullScreen(nullptr, nullptr, this, ac);
    ac->setDefaultShortcut(mShowFullScreenAction, Qt::Key_F11);
    connect(mShowFullScreenAction, &QAction::toggled, this, &KAIChatMainWindow::slotFullScreen);

    if (menuBar()) {
        mHamburgerMenu = KStandardAction::hamburgerMenu(nullptr, nullptr, actionCollection());
        mHamburgerMenu->setShowMenuBarAction(mShowMenuBarAction);
        mHamburgerMenu->setMenuBar(menuBar());
        mHamburgerMenu->hideActionsOf(toolBar());
        connect(mHamburgerMenu, &KHamburgerMenu::aboutToShowMenu, this, [this]() {
            updateHamburgerMenu();
            // Immediately disconnect. We only need to run this once, but on demand.
            // NOTE: The nullptr at the end disconnects all connections between
            // q and mHamburgerMenu's aboutToShowMenu signal.
            disconnect(mHamburgerMenu, &KHamburgerMenu::aboutToShowMenu, this, nullptr);
        });
    }
}

void KAIChatMainWindow::updateHamburgerMenu()
{
    delete mHamburgerMenu->menu();
    auto menu = new QMenu(this);
    menu->addAction(actionCollection()->action(KStandardActions::name(KStandardActions::Quit)));
    mHamburgerMenu->setMenu(menu);
}

void KAIChatMainWindow::slotClose()
{
    mReallyClose = true;
    close();
}

void KAIChatMainWindow::slotFullScreen(bool t)
{
    KToggleFullScreenAction::setFullScreen(this, t);
    QMenuBar *mb = menuBar();
    if (t) {
        auto b = new QToolButton(mb);
        b->setDefaultAction(mShowFullScreenAction);
        b->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Ignored));
        b->setFont(QFontDatabase::systemFont(QFontDatabase::SmallestReadableFont));
        mb->setCornerWidget(b, Qt::TopRightCorner);
        b->setVisible(true);
        b->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    } else {
        QWidget *w = mb->cornerWidget(Qt::TopRightCorner);
        if (w) {
            w->deleteLater();
        }
    }
}

void KAIChatMainWindow::slotConfigure()
{
    // TODO
}

void KAIChatMainWindow::slotShowArchive(bool checked)
{
    mMainWidget->showArchive(checked);
}

void KAIChatMainWindow::slotToggleMenubar(bool dontShowWarning)
{
    if (menuBar()) {
        if (mShowMenuBarAction->isChecked()) {
            menuBar()->show();
        } else {
            if (!dontShowWarning && (!toolBar()->isVisible() || !toolBar()->actions().contains(mHamburgerMenu))) {
                const QString accel = mShowMenuBarAction->shortcut().toString(QKeySequence::NativeText);
                KMessageBox::information(this,
                                         i18n("<qt>This will hide the menu bar completely."
                                              " You can show it again by typing %1.</qt>",
                                              accel),
                                         i18nc("@title:window", "Hide menu bar"),
                                         QStringLiteral("HideMenuBarWarning"));
            }
            menuBar()->hide();
        }
        KAIChatGlobalConfig::self()->setShowMenuBar(mShowMenuBarAction->isChecked());
        KAIChatGlobalConfig::self()->save();
    }
}

void KAIChatMainWindow::slotActivateRequested(const QStringList &arguments, const QString &workingDirectory)
{
    Q_UNUSED(workingDirectory)
    if (!arguments.isEmpty()) {
        QCommandLineParser parser;
        // TODO RuqolaCommandLineParser commandLineParser(&parser);
        parser.parse(arguments);
        // TODO parseCommandLine(&parser);
    }
#if !defined(Q_OS_WIN) && !defined(Q_OS_MACOS)
    KWindowSystem::updateStartupId(windowHandle());
    KWindowSystem::activateWindow(windowHandle());
#else
    activateWindow();
#endif
}

#include "moc_kaichatmainwindow.cpp"
