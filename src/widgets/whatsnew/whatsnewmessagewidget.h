/*
   SPDX-FileCopyrightText: 2023-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once
#include "libkaichatwidgets_private_export.h"
#include <KMessageWidget>

class LIBKAICHATWIDGETS_TESTS_EXPORT WhatsNewMessageWidget : public KMessageWidget
{
    Q_OBJECT
public:
    explicit WhatsNewMessageWidget(QWidget *parent = nullptr);
    ~WhatsNewMessageWidget() override;

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotLinkActivated(const QString &contents);
};
