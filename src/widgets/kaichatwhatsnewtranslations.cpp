/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatwhatsnewtranslations.h"
using namespace Qt::Literals::StringLiterals;
KAIChatWhatsNewTranslations::KAIChatWhatsNewTranslations() = default;

KAIChatWhatsNewTranslations::~KAIChatWhatsNewTranslations() = default;

// Use by newFeaturesMD5
QList<KLazyLocalizedString> KAIChatWhatsNewTranslations::lastNewFeatures() const
{
    const QList<KLazyLocalizedString> info{
        kli18n("Add Grok instance support."),
        kli18n("Add User Feedback support."),
        kli18n("Allow to show model info."),
    };
    return info;
}

QList<TextAddonsWidgets::WhatsNewInfo> KAIChatWhatsNewTranslations::createWhatsNewInfo() const
{
    QList<TextAddonsWidgets::WhatsNewInfo> listInfo;
    {
        TextAddonsWidgets::WhatsNewInfo info;
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
        TextAddonsWidgets::WhatsNewInfo info;
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
        TextAddonsWidgets::WhatsNewInfo info;
        info.setNewFeatures({
            i18n("Allow to copy block code to clipboard."),
            i18n("Show number of string found in statusbar."),
            i18n("Implement quick search."),
            i18n("Add quick search bar in quick ask dialog."),
            i18n("Add restore configure settings value."),
            i18n("Allow to configure text to speech."),
            i18n("Add tool plugin icon name."),
            i18n("Add attachment support."),
            i18n("Add new icon."),
            i18n("Add debug command line."),
            i18n("Add wikipedia, weather tools plugins (provided by kaichat-addons)."),
            i18n("Store Pending Typed Info in Database."),
            i18n("Allow to add attachment files from command line."),
            i18n("Add icon in configure ollama models."),
            i18n("Allow to use specific Ollama environment variables."),
        });

        info.setVersion(u"0.6.0"_s);
        info.setBugFixings({i18n("Fix multi tools plugins call.")});

        listInfo.append(std::move(info));
    }
    {
        TextAddonsWidgets::WhatsNewInfo info;
        QStringList lst;
        for (const KLazyLocalizedString &l : lastNewFeatures()) {
            lst += l.toString();
        }
        info.setNewFeatures(lst);
        info.setVersion(u"0.7.0"_s);

        listInfo.append(std::move(info));
    }
    return listInfo;
}
