/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "kaichatdatabasemessagejsonwidget.h"
#include "databasedialog/jsonplaintexteditwidget.h"
#include <QVBoxLayout>
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseMessageJsonWidget::KAIChatDatabaseMessageJsonWidget(QWidget *parent)
    : QWidget{parent}
    , mJsonPlainTextEditWidget(new JsonPlainTextEditWidget(this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});

    mJsonPlainTextEditWidget->setObjectName(u"mJsonPlainTextEditWidget"_s);
    mainLayout->addWidget(mJsonPlainTextEditWidget);
}

KAIChatDatabaseMessageJsonWidget::~KAIChatDatabaseMessageJsonWidget() = default;

void KAIChatDatabaseMessageJsonWidget::setJson(const QString &json)
{
    mJsonPlainTextEditWidget->setPlainText(json);
}

#include "moc_kaichatdatabasemessagejsonwidget.cpp"
