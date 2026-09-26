/*
   SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "kaichatconfigureprivacywidget.h"
#include <QApplication>
#include <QClipboard>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <TextAutoGenerateText/TextAutoGenerateManager>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigurePrivacyWidget::KAIChatConfigurePrivacyWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    auto hbox = new QHBoxLayout;
    hbox->setObjectName(u"mainLayout"_s);
    hbox->setContentsMargins({});

    auto label = new QLabel(i18n("Database Repository:"), this);
    label->setObjectName(u"label"_s);
    hbox->addWidget(label);

    const QString path = manager->localDatabasePath();
    auto lineEditPath = new QLineEdit(path, this);
    lineEditPath->setObjectName(u"labelPath"_s);
    lineEditPath->setReadOnly(true);
    hbox->addWidget(lineEditPath);

    auto copyToolButton = new QToolButton(this);
    copyToolButton->setObjectName(u"copyToolButton"_s);
    copyToolButton->setAutoRaise(true);
    copyToolButton->setIcon(QIcon::fromTheme(u"edit-copy"_s));
    hbox->addWidget(copyToolButton);

    mainLayout->addLayout(hbox);
    mainLayout->addStretch(1);

    connect(copyToolButton, &QToolButton::clicked, this, [path]() {
        QClipboard *cb = QApplication::clipboard();
        cb->setText(path, QClipboard::Clipboard);
        cb->setText(path, QClipboard::Selection);
    });
}

KAIChatConfigurePrivacyWidget::~KAIChatConfigurePrivacyWidget() = default;
#include "moc_kaichatconfigureprivacywidget.cpp"
