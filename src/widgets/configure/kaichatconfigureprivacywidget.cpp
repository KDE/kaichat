/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "kaichatconfigureprivacywidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <TextAutoGenerateText/TextAutoGenerateManager>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigurePrivacyWidget::KAIChatConfigurePrivacyWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QHBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    auto label = new QLabel(i18n("Database Repository:"), this);
    label->setObjectName(u"label"_s);
    mainLayout->addWidget(label);

    auto labelPath = new QLabel(manager->localDatabasePath(), this);
    labelPath->setObjectName(u"labelPath"_s);
    mainLayout->addWidget(labelPath, 1);
    labelPath->setTextInteractionFlags(Qt::TextSelectableByMouse);
}

KAIChatConfigurePrivacyWidget::~KAIChatConfigurePrivacyWidget() = default;
#include "moc_kaichatconfigureprivacywidget.cpp"
