/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatmainwindow.h"

#include "kaichatcentralwidget.h"

#include <KConfigGroup>
#include <KSharedConfig>

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
    // TODO setupActions();
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
