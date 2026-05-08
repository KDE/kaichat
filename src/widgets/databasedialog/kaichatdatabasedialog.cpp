/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasedialog.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseDialog::KAIChatDatabaseDialog(QWidget *parent)
    : QDialog(parent)
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    auto button = new QDialogButtonBox(QDialogButtonBox::Close, this);
    button->setObjectName(u"button"_s);
    mainLayout->addWidget(button);
    connect(button, &QDialogButtonBox::rejected, this, &KAIChatDatabaseDialog::reject);
}

KAIChatDatabaseDialog::~KAIChatDatabaseDialog() = default;

#include "moc_kaichatdatabasedialog.cpp"
