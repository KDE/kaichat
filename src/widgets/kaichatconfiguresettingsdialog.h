/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "libkaichatwidgets_private_export.h"
#include <KPageDialog>
#include <QObject>
class KAIChatConfigureGeneralWidget;
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatConfigureSettingsDialog : public KPageDialog
{
    Q_OBJECT
public:
    explicit KAIChatConfigureSettingsDialog(QWidget *parent = nullptr);
    ~KAIChatConfigureSettingsDialog() override;

private:
    LIBKAICHATWIDGETS_NO_EXPORT void readConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void writeConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void slotAccepted();
    LIBKAICHATWIDGETS_NO_EXPORT void load();
    KAIChatConfigureGeneralWidget *const mConfigureGeneralWidget;
};
