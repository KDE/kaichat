/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigureretentionwidget.h"
#include <KLocalizedString>
#include <QCheckBox>
#include <QSpinBox>
#include <QVBoxLayout>
using namespace Qt::Literals::StringLiterals;
KAIChatConfigureRetentionWidget::KAIChatConfigureRetentionWidget(QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);
    mainLayout->setContentsMargins({});
}

KAIChatConfigureRetentionWidget::~KAIChatConfigureRetentionWidget() = default;

void KAIChatConfigureRetentionWidget::save()
{
    // TODO
}

void KAIChatConfigureRetentionWidget::load()
{
    // TODO
}

void KAIChatConfigureRetentionWidget::restoreToDefaults()
{
    // TODO
}
