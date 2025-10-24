/*
   SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kaichatchangefontsizemenu.h"
#include "textautogeneratetext/textautogeneratetextglobalconfig.h"

#include "kaichat_widget_debug.h"
#include <KLocalizedString>
#include <QGuiApplication>
#include <QMenu>

using namespace Qt::Literals::StringLiterals;
KAIChatChangeFontSizeMenu::KAIChatChangeFontSizeMenu(QObject *parent)
    : KActionMenu{parent}
{
    setText(i18n("Font Size"));

    auto increaseFontSizeAction = new QAction(QIcon::fromTheme(u"zoom-in"_s), i18nc("@action", "Increase Font"), this);
    increaseFontSizeAction->setShortcut(Qt::CTRL | Qt::Key_Plus);
    menu()->addAction(increaseFontSizeAction);
    connect(increaseFontSizeAction, &QAction::triggered, this, [this]() {
        changeFontSize(+1);
    });
    auto decreaseFontSizeAction = new QAction(QIcon::fromTheme(u"zoom-out"_s), i18nc("@action", "Decrease Font"), this);
    decreaseFontSizeAction->setShortcut(Qt::CTRL | Qt::Key_Minus);
    menu()->addAction(decreaseFontSizeAction);
    connect(decreaseFontSizeAction, &QAction::triggered, this, [this]() {
        changeFontSize(-1);
    });
}

KAIChatChangeFontSizeMenu::~KAIChatChangeFontSizeMenu() = default;

void KAIChatChangeFontSizeMenu::changeFontSize(int offset)
{
    QFont f;
    if (TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->useCustomFont()) {
        f = TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->generalFont();
    } else {
        TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setUseCustomFont(true);
        f = qApp->font();
    }
    const int newSize = f.pointSize() + offset;
    if (newSize < 5 || newSize > 30) {
        qCDebug(KAICHAT_WIDGET_LOG) << " We can't use font size < 5 or > 30";
        return;
    }
    f.setPointSize(newSize);
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->setGeneralFont(f);
    TextAutoGenerateText::TextAutogenerateTextGlobalConfig::self()->save();
    qApp->setFont(f);
    Q_EMIT fontChanged();
}

#include "moc_kaichatchangefontsizemenu.cpp"
