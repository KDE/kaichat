/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "accountinfosource.h"

#include <KConfig>
#include <KLocalizedString>
#include <QVariant>
#include <TextAutoGenerateText/TextAutoGenerateTextUtils>

using namespace Qt::Literals::StringLiterals;
AccountInfoSource::AccountInfoSource()
    : KUserFeedback::AbstractDataSource(u"accounts"_s, KUserFeedback::Provider::DetailedSystemInformation)
{
}

AccountInfoSource::~AccountInfoSource() = default;

QString AccountInfoSource::name() const
{
    return i18n("Account information");
}

QString AccountInfoSource::description() const
{
    return i18n("Return the number of account.");
}

QVariant AccountInfoSource::data()
{
    KConfig config(TextAutoGenerateText::TextAutoGenerateTextUtils::instanceConfigFileName());
    const QStringList lst = TextAutoGenerateText::TextAutoGenerateTextUtils::instancesList(&config);
    const QVariantMap m{{u"value"_s, lst.count()}};
    return m;
}
