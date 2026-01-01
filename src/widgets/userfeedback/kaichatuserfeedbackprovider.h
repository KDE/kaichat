/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "libkaichatwidgets_export.h"
#include <KUserFeedback/Provider>

class LIBKAICHATWIDGETS_EXPORT KAIChatUserFeedbackProvider : public KUserFeedback::Provider
{
    Q_OBJECT
public:
    explicit KAIChatUserFeedbackProvider(QObject *parent = nullptr);
    ~KAIChatUserFeedbackProvider() override;
};
