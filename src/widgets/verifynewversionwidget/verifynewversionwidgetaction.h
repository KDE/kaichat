/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once
#include "libkaichatwidgets_private_export.h"
#include <QObject>
class QAction;
class LIBKAICHATWIDGETS_TESTS_EXPORT VerifyNewVersionWidgetAction : public QObject
{
    Q_OBJECT
public:
    explicit VerifyNewVersionWidgetAction(QObject *parent = nullptr);
    ~VerifyNewVersionWidgetAction() override;

    [[nodiscard]] bool canVerifyNewVersion() const;

    [[nodiscard]] QAction *verifyNewVersionAction();

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotVerifyNewVersion();
    QAction *mVerifyNewVersionAction = nullptr;
};
