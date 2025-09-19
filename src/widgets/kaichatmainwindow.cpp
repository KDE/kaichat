/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatmainwindow.h"

#include "kaichatcentralwidget.h"
#include "kaichatchangefontsizemenu.h"
#include "kaichatcommandlineparser.h"
#include "kaichatconfiguresettingsdialog.h"
#include "kaichatexportmenu.h"
#include "kaichatglobalconfig.h"
#include "kaichatnotificatifieritem.h"
#include "kaichatutils.h"
#include "whatsnew/whatsnewdialog.h"
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
#include "verifynewversionwidget/verifynewversionwidgetaction.h"
#endif

#include <TextAutoGenerateText/TextAutoGenerateManager>
#include <TextAutoGenerateText/TextAutoGenerateQuickAskDialog>
#include <TextAutoGenerateText/TextAutoGenerateTextInstancesManager>

#include <KActionCollection>
#include <KActionMenu>
#include <KColorSchemeManager>
#include <KColorSchemeMenu>
#include <KConfigGroup>
#include <KHamburgerMenu>
#include <KLocalizedString>
#include <KMessageBox>
#include <KNotification>
#include <KNotifyConfigWidget>
#include <KSharedConfig>
#include <KStandardAction>
#include <KStandardActions>
#include <KToggleAction>
#include <KToggleFullScreenAction>
#include <KToolBar>
#include <KWindowSystem>
#include <QApplication>
#include <QCommandLineParser>
#include <QFileDialog>
#include <QFontDatabase>
#include <QMenuBar>
#include <QPointer>
namespace
{
const char myKAIChatMainWindowGroupName[] = "KAIChatMainWindow";
}
using namespace Qt::Literals::StringLiterals;
KAIChatMainWindow::KAIChatMainWindow(QWidget *parent)
    : KXmlGuiWindow(parent)
    , mManager(new TextAutoGenerateText::TextAutoGenerateManager(this))
    , mMainWidget(new KAIChatCentralWidget(mManager, this))
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
    , mVerifyNewVersionWidgetAction(new VerifyNewVersionWidgetAction(this))
#endif
{
    mMainWidget->setObjectName(u"mMainWidget"_s);
    setCentralWidget(mMainWidget);
    setupActions();
    setupGUI();
    readConfig();
    createSystemTray();
    mShowMenuBarAction->setChecked(KAIChatGlobalConfig::self()->showMenuBar());
    slotToggleMenubar(true);
    connect(mManager, &TextAutoGenerateText::TextAutoGenerateManager::showArchiveChanged, this, [this]() {
        mShowArchivedAction->setChecked(mManager->showArchived());
    });
    connect(mManager, &TextAutoGenerateText::TextAutoGenerateManager::loadEngineDone, this, &KAIChatMainWindow::updateActions);
    connect(mManager, &TextAutoGenerateText::TextAutoGenerateManager::currentChatIdChanged, this, &KAIChatMainWindow::updateActions);
    connect(mManager, &TextAutoGenerateText::TextAutoGenerateManager::downloadModelFinished, this, &KAIChatMainWindow::slotDownloadModelFinished);
    disableActions();
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

void KAIChatMainWindow::createSystemTray()
{
#if !defined(Q_OS_IOS)
    if (!KAIChatGlobalConfig::self()->enableSystemTray()) {
        delete mNotification;
        mNotification = nullptr;
        return;
    }
    if (!mNotification) {
        mNotification = new KAIChatNotificatifierItem(this);
        auto trayMenu = mNotification->contextMenu();

        trayMenu->addAction(actionCollection()->action(KStandardActions::name(KStandardActions::Preferences)));
    }
#endif
}

void KAIChatMainWindow::setupActions()
{
    KActionCollection *ac = actionCollection();

    mShowMenuBarAction = KStandardAction::showMenubar(this, &KAIChatMainWindow::slotToggleMenubar, ac);

    auto showWhatsNewAction = new QAction(QIcon(u":/kaichat/kaichat.svg"_s), i18n("What's new"), this);
    ac->addAction(u"whatsnew_kaichat"_s, showWhatsNewAction);
    connect(showWhatsNewAction, &QAction::triggered, this, &KAIChatMainWindow::slotWhatsNew);

    mShowArchivedAction = new KToggleAction(i18nc("@action", "Show Archive"), this);
    connect(mShowArchivedAction, &KToggleAction::triggered, this, &KAIChatMainWindow::slotShowArchive);
    ac->addAction(u"show_archive"_s, mShowArchivedAction);

    mExportMenu = new KAIChatExportMenu(this);
    ac->addAction(u"export_menu"_s, mExportMenu);
    connect(mExportMenu, &KAIChatExportMenu::exportInfoRequested, this, &KAIChatMainWindow::slotExportInfoRequested);

    KStandardAction::find(this, &KAIChatMainWindow::slotSearchText, ac);

    auto manager = KColorSchemeManager::instance();
    ac->addAction(u"colorscheme_menu"_s, KColorSchemeMenu::createMenu(manager, this));

    KStandardActions::quit(this, &KAIChatMainWindow::slotClose, ac);
    KStandardActions::preferences(this, &KAIChatMainWindow::slotConfigure, ac);

    KStandardActions::configureNotifications(this, &KAIChatMainWindow::slotConfigureNotifications, ac);

    mShowFullScreenAction = KStandardAction::fullScreen(nullptr, nullptr, this, ac);
    ac->setDefaultShortcut(mShowFullScreenAction, Qt::Key_F11);
    connect(mShowFullScreenAction, &QAction::toggled, this, &KAIChatMainWindow::slotFullScreen);

    mChangeFontSizeAction = new KAIChatChangeFontSizeMenu(this);
    ac->addAction(u"change_font_size"_s, mChangeFontSizeAction);
    connect(mChangeFontSizeAction, &KAIChatChangeFontSizeMenu::fontChanged, this, [this]() {
        Q_EMIT mManager->fontSizeChanged();
    });

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

    mShowQuickAskAction = new QAction(i18n("Open Quick Ask..."), this);
    ac->addAction(u"show_quick_ask"_s, mShowQuickAskAction);
    connect(mShowQuickAskAction, &QAction::triggered, this, &KAIChatMainWindow::slotQuickAsk);

#if defined(Q_OS_WIN) || defined(Q_OS_MACOS)
    auto verifyNewVersionAction = mVerifyNewVersionWidgetAction->verifyNewVersionAction();
    ac->addAction(u"verify_check_version"_s, verifyNewVersionAction);
#endif
}

void KAIChatMainWindow::slotQuickAsk()
{
    KAIChatUtils::createQuickAsk(this);
}

void KAIChatMainWindow::slotWhatsNew()
{
    WhatsNewDialog dlg(this);
    dlg.updateInformations();
    dlg.exec();
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
    QPointer<KAIChatConfigureSettingsDialog> dlg = new KAIChatConfigureSettingsDialog(mManager, this);
    if (dlg->exec()) {
        if (KAIChatGlobalConfig::self()->useCustomFont()) {
            qApp->setFont(KAIChatGlobalConfig::self()->generalFont());
        } else {
            qApp->setFont(QFontDatabase::systemFont(QFontDatabase::GeneralFont));
        }
        createSystemTray();
        Q_EMIT mManager->fontSizeChanged();
        Q_EMIT mManager->configChanged();
        updateActions();
    }
    delete dlg;
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
                                         u"HideMenuBarWarning"_s);
            }
            menuBar()->hide();
        }
        KAIChatGlobalConfig::self()->setShowMenuBar(mShowMenuBarAction->isChecked());
        KAIChatGlobalConfig::self()->save();
    }
}

void KAIChatMainWindow::slotActivateRequested(const QStringList &arguments, [[maybe_unused]] const QString &workingDirectory)
{
    if (!arguments.isEmpty()) {
        QCommandLineParser parser;
        parser.parse(arguments);
        const KAIChatCommandLineParser commandLineParser(&parser);
        parser.parse(arguments);
        parseCommandLine(&parser);
    }
#if !defined(Q_OS_WIN) && !defined(Q_OS_MACOS)
    KWindowSystem::updateStartupId(windowHandle());
    KWindowSystem::activateWindow(windowHandle());
#else
    activateWindow();
#endif
}

void KAIChatMainWindow::slotSearchText()
{
    mMainWidget->searchText();
}

void KAIChatMainWindow::slotExportInfoRequested()
{
    const QString fileName = QFileDialog::getSaveFileName(this, i18nc("@title:window", "Export Chats"), QDir::homePath());
    if (fileName.isEmpty()) {
        return;
    }
    const TextAutoGenerateText::TextAutoGenerateExportChatBaseJob::ExportChatInfo info{
        .filename = fileName,
        .chatTitle = mMainWidget->chatCurrentTitle(),
        .listMessages = mMainWidget->messagesFromCurrentChat(),
    };
    mExportMenu->setExportChatInfo(std::move(info));
}

void KAIChatMainWindow::disableActions()
{
    mShowQuickAskAction->setEnabled(false);
    mExportMenu->setEnabled(false);
}

void KAIChatMainWindow::updateActions()
{
    const bool status = !mManager->textAutoGenerateTextInstancesManager()->isEmpty();
    qDebug() << " void KAIChatMainWindow::updateActions()";
    mShowQuickAskAction->setEnabled(status);
    mExportMenu->setEnabled(status && !mManager->currentChatId().isEmpty());
}

void KAIChatMainWindow::parseCommandLine(QCommandLineParser *parser)
{
    if (parser->isSet(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SwitchToChat))) {
        const QString chatName = parser->value(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SwitchToChat));
        if (!chatName.isEmpty()) {
            mManager->switchToChat(chatName);
        }
    }
    if (parser->isSet(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SwitchToChatFromId))) {
        const QString chatIdentifier =
            parser->value(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::SwitchToChatFromId));
        if (!chatIdentifier.isEmpty()) {
            mManager->switchToChatId(chatIdentifier.toLatin1());
        }
    }
    if (parser->isSet(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::Instance))) {
        qDebug() << " INSTANCE ***************";
        // TODO
    }
    if (parser->isSet(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::NewChat))) {
        const QString newChatName = parser->value(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::NewChat));
        mManager->createNewChat(newChatName);
    }
    if (parser->isSet(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::AskMessage))) {
        const QString message = parser->value(KAIChatCommandLineParser::optionParserFromEnum(KAIChatCommandLineParser::OptionParser::AskMessage));
        mManager->ask(message);
    }
}

void KAIChatMainWindow::slotDownloadModelFinished(const QString &modelName)
{
    auto notification = new KNotification(u"download-done"_s, KNotification::CloseOnTimeout);
    notification->setTitle(i18n("Model Download Done"));
    notification->setText(i18n("Model %1 was download.", modelName));
    notification->sendEvent();
}

void KAIChatMainWindow::slotConfigureNotifications()
{
    KNotifyConfigWidget::configure(this);
}

#include "moc_kaichatmainwindow.cpp"
