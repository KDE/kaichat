/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigurespellcheckingwidget.h"
#include <QVBoxLayout>
#include <Sonnet/ConfigWidget>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureSpellCheckingWidget::KAIChatConfigureSpellCheckingWidget(QWidget *parent)
    : QWidget(parent)
    , mConfigWidget(new Sonnet::ConfigWidget(this))
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});
    mConfigWidget->setObjectName(u"mConfigWidget"_s);
    mainLayout->addWidget(mConfigWidget);
}

KAIChatConfigureSpellCheckingWidget::~KAIChatConfigureSpellCheckingWidget() = default;

void KAIChatConfigureSpellCheckingWidget::save()
{
    mConfigWidget->save();
}

void KAIChatConfigureSpellCheckingWidget::load()
{
    // Nothing
}

void KAIChatConfigureSpellCheckingWidget::restoreToDefaults()
{
    mConfigWidget->slotDefault();
}

#include "moc_kaichatconfigurespellcheckingwidget.cpp"
