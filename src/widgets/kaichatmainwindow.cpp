/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatmainwindow.h"

#include "kaichatcentralwidget.h"

#include <KActionCollection>
#include <KConfigGroup>
#include <KLocalizedString>
#include <KMessageBox>
#include <KSharedConfig>
#include <KStandardActions>
#include <KToolBar>
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
    setupGUI(/*QStringLiteral(":/kxmlgui5/ruqola/ruqolaui.rc")*/);
    readConfig();
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

    KStandardActions::quit(this, &KAIChatMainWindow::slotClose, ac);
    KStandardActions::preferences(this, &KAIChatMainWindow::slotConfigure, ac);
    // KStandardActions::configureNotifications(this, &RuqolaMainWindow::slotConfigureNotifications, ac);
}

void KAIChatMainWindow::slotClose()
{
    mReallyClose = true;
    close();
}

void KAIChatMainWindow::slotConfigure()
{
    // TODO
}

void KAIChatMainWindow::slotToggleMenubar(bool dontShowWarning)
{
    /*
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
        RuqolaGlobalConfig::self()->setShowMenuBar(mShowMenuBarAction->isChecked());
        RuqolaGlobalConfig::self()->save();
    }
    */
}

#include "moc_kaichatmainwindow.cpp"
