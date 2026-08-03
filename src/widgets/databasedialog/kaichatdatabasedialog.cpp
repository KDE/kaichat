/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatdatabasedialog.h"
#include "databasedialog/kaichatdatabasewidget.h"
#include <KLocalizedString>
#include <KSharedConfig>
#include <KWindowConfig>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QWindow>
#include <TextAddonsWidgets/LoadDialogSizeUtils>
namespace
{
const char myConfigGroupName[] = "KAIChatDatabaseDialog";
}
using namespace Qt::Literals::StringLiterals;
KAIChatDatabaseDialog::KAIChatDatabaseDialog(TextAutoGenerateText::TextAutoGenerateManager *manager, QWidget *parent)
    : QDialog(parent)
    , mDatabaseWidget(new KAIChatDatabaseWidget(manager, this))
{
    setWindowTitle(i18nc("@title:window", "Debug Database"));

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    mDatabaseWidget->setObjectName(u"mDatabaseWidget"_s);
    mainLayout->addWidget(mDatabaseWidget);

    auto button = new QDialogButtonBox(QDialogButtonBox::Close, this);
    button->setObjectName(u"button"_s);
    mainLayout->addWidget(button);
    connect(button, &QDialogButtonBox::rejected, this, &KAIChatDatabaseDialog::reject);
    readConfig();
}

KAIChatDatabaseDialog::~KAIChatDatabaseDialog()
{
    writeConfig();
}

void KAIChatDatabaseDialog::readConfig()
{
    create(); // ensure a window is created
    TextAddonsWidgets::LoadDialogSizeUtils::loadDialogSizeScaled(this, QLatin1StringView(myConfigGroupName), 800, 600);
}

void KAIChatDatabaseDialog::writeConfig()
{
    KConfigGroup group(KSharedConfig::openStateConfig(), QLatin1StringView(myConfigGroupName));
    KWindowConfig::saveWindowSize(windowHandle(), group);
}

#include "moc_kaichatdatabasedialog.cpp"
