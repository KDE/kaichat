/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "exampletexttoolplugindialog.h"
#include "core/tools/textautogeneratetexttoolplugin.h"
#include "exampletexttoolpluginwidget.h"
#include <qboxlayout.h>
#include <qdialogbuttonbox.h>
using namespace Qt::Literals::StringLiterals;
ExampleTextToolPluginDialog::ExampleTextToolPluginDialog(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent)
    : QDialog(parent)
    , mExampleTextToolPluginWidget(new ExampleTextToolPluginWidget(plugin, this))
{
    // don't translate here.
    setWindowTitle(plugin ? plugin->displayName() : u"Example Text Tool"_s);

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    mExampleTextToolPluginWidget->setObjectName(u"mExampleTextToolPluginWidget"_s);
    mainLayout->addWidget(mExampleTextToolPluginWidget);

    auto button = new QDialogButtonBox(QDialogButtonBox::Close, this);
    button->setObjectName(u"button"_s);
    mainLayout->addWidget(button);
    connect(button, &QDialogButtonBox::rejected, this, &ExampleTextToolPluginDialog::reject);
}

ExampleTextToolPluginDialog::~ExampleTextToolPluginDialog() = default;

#include "moc_exampletexttoolplugindialog.cpp"
