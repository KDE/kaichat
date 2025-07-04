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
        kli18n("Add what's new support."),
        kli18n("Add instance support."),
        kli18n("Add Mardown support."),
        kli18n("Add Highlighting support."),
    };
    return info;
}

QList<WhatsNewInfo> WhatsNewTranslations::createWhatsNewInfo() const
{
    QList<WhatsNewInfo> listInfo;
    {
        WhatsNewInfo info;
        QStringList lst;
        for (const KLazyLocalizedString &l : lastNewFeatures()) {
            lst += l.toString();
        }
        info.setNewFeatures(lst);
        info.setVersion(u"0.3.3"_s);
        // info.setBugFixings({});

        listInfo.append(std::move(info));
    }
    return listInfo;
}
