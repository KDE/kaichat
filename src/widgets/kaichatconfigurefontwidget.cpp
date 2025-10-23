/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigurefontwidget.h"

#include "kaichatglobalconfig.h"
#include <KFontChooser>
#include <KLocalizedString>

#include <QCheckBox>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;
KAIChatConfigureFontWidget::KAIChatConfigureFontWidget(QWidget *parent)
    : QWidget(parent)
    , mCustomFontCheck(new QCheckBox(i18nc("@option:check", "&Use custom fonts"), this))
    , mFontChooser(new KFontChooser(KFontChooser::DisplayFrame, this))
{
    mFontChooser->setMinVisibleItems(4);
    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    mCustomFontCheck->setObjectName(u"mCustomFontCheck"_s);
    mainLayout->addWidget(mCustomFontCheck);

    mFontChooser->setObjectName(u"mFontChooser"_s);
    mFontChooser->setEnabled(false); // since !mCustomFontCheck->isChecked()
    mainLayout->addWidget(mFontChooser);
    connect(mCustomFontCheck, &QCheckBox::toggled, mFontChooser, &KFontChooser::setEnabled);
}

KAIChatConfigureFontWidget::~KAIChatConfigureFontWidget() = default;

void KAIChatConfigureFontWidget::save()
{
    KAIChatGlobalConfig::self()->setUseCustomFont(mCustomFontCheck->isChecked());
    KAIChatGlobalConfig::self()->setGeneralFont(mFontChooser->font());
    KAIChatGlobalConfig::self()->save();
}

void KAIChatConfigureFontWidget::load()
{
    mCustomFontCheck->setChecked(KAIChatGlobalConfig::self()->useCustomFont());
    mFontChooser->setFont(KAIChatGlobalConfig::self()->generalFont());
}

void KAIChatConfigureFontWidget::restoreToDefaults()
{
    const bool bUseDefaults = KAIChatGlobalConfig::self()->useDefaults(true);
    const bool customFontCheck = KAIChatGlobalConfig::self()->useCustomFont();
    const QFont generalFont = KAIChatGlobalConfig::self()->generalFont();
    mCustomFontCheck->setChecked(customFontCheck);
    mFontChooser->setFont(generalFont);
    KAIChatGlobalConfig::self()->useDefaults(bUseDefaults);
}

#include "moc_kaichatconfigurefontwidget.cpp"
