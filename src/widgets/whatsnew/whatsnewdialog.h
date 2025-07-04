/*
   SPDX-FileCopyrightText: 2023-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once

#include "libkaichatwidgets_export.h"
#include <QDialog>
class WhatsNewWidget;
class LIBKAICHATWIDGETS_EXPORT WhatsNewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WhatsNewDialog(QWidget *parent = nullptr);
    ~WhatsNewDialog() override;

    void updateInformations();

private:
    LIBKAICHATWIDGETS_NO_EXPORT void readConfig();
    LIBKAICHATWIDGETS_NO_EXPORT void writeConfig();
    WhatsNewWidget *const mWhatsNewWidget;
};
