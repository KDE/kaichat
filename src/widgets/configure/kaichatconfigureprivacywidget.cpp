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
#include <TextAutoGenerateText/TextAutoGenerateManager>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigurePrivacyWidget::KAIChatConfigurePrivacyWidget(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QWidget{parent}
{
    auto mainLayout = new QHBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    auto label = new QLabel(i18n("Database Repository:"), this);
    label->setObjectName(u"label"_s);
    mainLayout->addWidget(label, 0, Qt::AlignTop);

    const QString path = manager->localDatabasePath();
    auto lineEditPath = new QLineEdit(path, this);
    lineEditPath->setObjectName(u"labelPath"_s);
    lineEditPath->setReadOnly(true);
    mainLayout->addWidget(lineEditPath, 1, Qt::AlignTop);

    auto copyToolButton = new QToolButton(this);
    copyToolButton->setObjectName(u"copyToolButton"_s);
    copyToolButton->setAutoRaise(true);
    copyToolButton->setIcon(QIcon::fromTheme(u"edit-copy"_s));
    mainLayout->addWidget(copyToolButton, 1, Qt::AlignTop);

    connect(copyToolButton, &QToolButton::clicked, this, [path]() {
        QClipboard *cb = QApplication::clipboard();
        cb->setText(path, QClipboard::Clipboard);
        cb->setText(path, QClipboard::Selection);
    });
}

KAIChatConfigurePrivacyWidget::~KAIChatConfigurePrivacyWidget() = default;
#include "moc_kaichatconfigureprivacywidget.cpp"
