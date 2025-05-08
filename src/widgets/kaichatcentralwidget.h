/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once

#include "libkaichatwidgets_private_export.h"
#include <QWidget>
namespace TextAutoGenerateText
{
class TextAutoGenerateWidget;
}
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatCentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatCentralWidget(QWidget *parent = nullptr);
    ~KAIChatCentralWidget() override;

private:
    TextAutoGenerateText::TextAutoGenerateWidget *const mTextAutogenerateWidget;
};
