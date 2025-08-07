/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "webshortcuttextinterface.h"

#include <KIO/KUriFilterSearchProviderActions>

#include <QMenu>

WebShortcutTextInterface::WebShortcutTextInterface(QObject *parent)
    : TextAutoGenerateText::TextAutoGeneratePluginTextInterface(parent)
    , mWebShortcutMenuManager(new KIO::KUriFilterSearchProviderActions(this))
{
}

WebShortcutTextInterface::~WebShortcutTextInterface() = default;

void WebShortcutTextInterface::addAction(QMenu *menu)
{
    menu->addSeparator();
    mWebShortcutMenuManager->addWebShortcutsToMenu(menu);
}

void WebShortcutTextInterface::setSelectedText(const QString &str)
{
    mWebShortcutMenuManager->setSelectedText(str);
}

#include "moc_webshortcuttextinterface.cpp"
