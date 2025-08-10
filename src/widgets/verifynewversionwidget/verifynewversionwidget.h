/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QWidget>
class QLabel;
class LIBKAICHATWIDGETS_TESTS_EXPORT VerifyNewVersionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VerifyNewVersionWidget(QWidget *parent = nullptr);
    ~VerifyNewVersionWidget() override;

    void checkNewVersion();

private:
    LIBKAICHATWIDGETS_NO_EXPORT void slotFoundNewVersion(const QUrl &url, bool found);
    LIBKAICHATWIDGETS_NO_EXPORT void checkCurrentVersion();
    LIBKAICHATWIDGETS_NO_EXPORT void slotFoundNextVersion(bool found);
    QLabel *const mCheckVersionResultLabel;
};
