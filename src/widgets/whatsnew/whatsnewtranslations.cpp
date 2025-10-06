/*
   SPDX-FileCopyrightText: 2024-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "whatsnewtranslations.h"
using namespace Qt::Literals::StringLiterals;

WhatsNewTranslations::WhatsNewTranslations() = default;

WhatsNewTranslations::~WhatsNewTranslations() = default;

// Use by newFeaturesMD5
QList<KLazyLocalizedString> WhatsNewTranslations::lastNewFeatures() const
{
    const QList<KLazyLocalizedString> info{};
    return info;
}

QList<WhatsNewInfo> WhatsNewTranslations::createWhatsNewInfo() const
{
    QList<WhatsNewInfo> listInfo;
    {
        WhatsNewInfo info;
        info.setNewFeatures({
            i18n("Add what's new support."),
            i18n("Add instance support."),
            i18n("Add Mardown support."),
            i18n("Add Highlighting support."),
        });
        info.setVersion(u"0.4.0"_s);
        info.setBugFixings({i18n("Fix allow delete chat. Bug %1", u"<a href=\"https://bugs.kde.org/show_bug.cgi?id=506687\"> 506687</a>"_s)});

        listInfo.append(std::move(info));
    }
    {
        WhatsNewInfo info;
        info.setNewFeatures({
            i18n("Add Quick Ask Dialog."),
            i18n("Allow to download Ollama on Windows/MacOs."),
            i18n("Use prompt during chating."),
            i18n("Add shared text and webshorcut plugin."),
            i18n("Allow to configure plugins."),
            i18n("Add new update widget."),
            i18n("Add progress indicator in chats list."),
            i18n("Allow to change font size."),
            i18n("Add command line for adding new chat room, displaying list of instances."),
            i18n("Add spell checking support."),
            i18n("Add Notification popup when model download done."),
            i18n("Allow to save and restore text and scrollbar position."),
            i18n("Allow to save and restore current chat."),
            i18n("Add option for showing list of title chats."),
            i18n("Add tools support."),
            i18n("Allow to switch from chat identifier."),
            i18n("Add Current Date Time tool."),
            i18n("Add progress tool message info."),
        });
        info.setVersion(u"0.5.0"_s);
        info.setBugFixings({i18n("Fix icon on windows.")});

        listInfo.append(std::move(info));
    }
    {
        WhatsNewInfo info;
        QStringList lst;
        for (const KLazyLocalizedString &l : lastNewFeatures()) {
            lst += l.toString();
        }
        info.setNewFeatures(lst);
        info.setVersion(u"0.6.0"_s);
        info.setBugFixings({});

        listInfo.append(std::move(info));
    }
    return listInfo;
}
