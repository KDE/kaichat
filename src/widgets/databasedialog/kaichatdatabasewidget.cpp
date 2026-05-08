/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasewidget.h"
#include <KLocalizedString>
#include <QVBoxLayout>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseWidget::KAIChatDatabaseWidget(QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName("mainLayout"_L1);
    mainLayout->setContentsMargins({});
    mainLayout->setSpacing(0);
}

KAIChatDatabaseWidget::~KAIChatDatabaseWidget() = default;

#include "moc_kaichatdatabasewidget.cpp"
