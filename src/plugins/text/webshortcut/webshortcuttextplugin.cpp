/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "webshortcuttextplugin.h"
#include "webshortcuttextinterface.h"
#include <KPluginFactory>

K_PLUGIN_CLASS_WITH_JSON(WebShortcutTextPlugin, "kaichat_webshortcuttextplugin.json")

WebShortcutTextPlugin::WebShortcutTextPlugin(QObject *parent, const QVariantList &)
    : TextAutoGenerateText::TextAutoGeneratePluginText(parent)
{
}

WebShortcutTextPlugin::~WebShortcutTextPlugin() = default;

TextAutoGenerateText::TextAutoGeneratePluginTextInterface *WebShortcutTextPlugin::createInterface(QObject *parent)
{
    return new WebShortcutTextInterface(parent);
}

int WebShortcutTextPlugin::order() const
{
    return 10;
}

#include "webshortcuttextplugin.moc"

#include "moc_webshortcuttextplugin.cpp"
