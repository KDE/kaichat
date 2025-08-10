/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QDialog>

class VerifyNewVersionWidget;
class LIBKAICHATWIDGETS_TESTS_EXPORT VerifyNewVersionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit VerifyNewVersionDialog(QWidget *parent = nullptr);
    ~VerifyNewVersionDialog() override;

    void checkNewVersion();

private:
    VerifyNewVersionWidget *const mVerifyNewVersionWidget;
};
