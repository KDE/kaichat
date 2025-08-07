/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "sharetextplugin.h"

#include "sharetextinterface.h"
#include <KPluginFactory>

K_PLUGIN_CLASS_WITH_JSON(ShareTextPlugin, "kaichat_sharetextplugin.json")

using namespace Qt::Literals::StringLiterals;
ShareTextPlugin::ShareTextPlugin(QObject *parent, const QVariantList &)
    : TextAutoGenerateText::TextAutoGeneratePluginText(parent)
{
}

ShareTextPlugin::~ShareTextPlugin() = default;

TextAutoGenerateText::TextAutoGeneratePluginTextInterface *ShareTextPlugin::createInterface(QObject *parent)
{
    auto shareTextInterface = new ShareTextInterface(parent);
    connect(shareTextInterface, &ShareTextInterface::errorMessage, this, &ShareTextPlugin::errorMessage);
    connect(shareTextInterface, &ShareTextInterface::successMessage, this, &ShareTextPlugin::successMessage);
    return shareTextInterface;
}

int ShareTextPlugin::order() const
{
    return 20;
}

#include "sharetextplugin.moc"

#include "moc_sharetextplugin.cpp"
