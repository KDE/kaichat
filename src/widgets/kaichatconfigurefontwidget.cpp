/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatconfigurefontwidget.h"
#include "textautogeneratetext/textautogeneratetextglobalconfig.h"

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
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setUseCustomFont(mCustomFontCheck->isChecked());
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setGeneralFont(mFontChooser->font());
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->save();
}

void KAIChatConfigureFontWidget::load()
{
    mCustomFontCheck->setChecked(TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useCustomFont());
    mFontChooser->setFont(TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->generalFont());
}

void KAIChatConfigureFontWidget::restoreToDefaults()
{
    const bool bUseDefaults = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(true);
    const bool customFontCheck = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useCustomFont();
    const QFont generalFont = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->generalFont();
    mCustomFontCheck->setChecked(customFontCheck);
    mFontChooser->setFont(generalFont);
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useDefaults(bUseDefaults);
}

#include "moc_kaichatconfigurefontwidget.cpp"
