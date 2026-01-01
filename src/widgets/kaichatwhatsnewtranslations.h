/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once
#include <TextAddonsWidgets/WhatsNewTranslationsBase>

class KAIChatWhatsNewTranslations : public TextAddonsWidgets::WhatsNewTranslationsBase
{
public:
    KAIChatWhatsNewTranslations();
    ~KAIChatWhatsNewTranslations() override;

    [[nodiscard]] QList<TextAddonsWidgets::WhatsNewInfo> createWhatsNewInfo() const override;
    [[nodiscard]] QList<KLazyLocalizedString> lastNewFeatures() const override;
};
