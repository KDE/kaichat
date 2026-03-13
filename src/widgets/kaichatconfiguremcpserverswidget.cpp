/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfiguremcpserverswidget.h"
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureMcpServersWidget::KAIChatConfigureMcpServersWidget(QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});
}

KAIChatConfigureMcpServersWidget::~KAIChatConfigureMcpServersWidget() = default;

void KAIChatConfigureMcpServersWidget::save()
{
}

void KAIChatConfigureMcpServersWidget::load()
{
}

void KAIChatConfigureMcpServersWidget::restoreToDefaults()
{
}

#include "moc_kaichatconfiguremcpserverswidget.cpp"
