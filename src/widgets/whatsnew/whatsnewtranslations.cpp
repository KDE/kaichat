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
    const QList<KLazyLocalizedString> info{
        kli18n("Add Quick Ask Dialog."),
    };
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
        QStringList lst;
        for (const KLazyLocalizedString &l : lastNewFeatures()) {
            lst += l.toString();
        }
        info.setNewFeatures(lst);
        info.setVersion(u"0.5.0"_s);

        listInfo.append(std::move(info));
    }
    return listInfo;
}
