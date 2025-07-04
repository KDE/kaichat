/*
   SPDX-FileCopyrightText: 2023-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QWidget>
class QComboBox;
class LIBKAICHATWIDGETS_TESTS_EXPORT WhatsNewComboBoxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WhatsNewComboBoxWidget(QWidget *parent = nullptr);
    ~WhatsNewComboBoxWidget() override;

    void addVersion(const QString &name, int identifier);

    void initializeVersion(int type);

Q_SIGNALS:
    void versionChanged(int type);

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotCurrentIndexChanged(int index);
    QComboBox *const mVersionComboBox;
};
