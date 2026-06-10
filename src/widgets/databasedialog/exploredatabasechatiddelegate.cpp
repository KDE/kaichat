/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "exploredatabasechatiddelegate.h"
#include <QHelpEvent>
#include <QToolTip>

ExploreDatabaseChatIdDelegate::ExploreDatabaseChatIdDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
}

ExploreDatabaseChatIdDelegate::~ExploreDatabaseChatIdDelegate() = default;

QString ExploreDatabaseChatIdDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
#if 0
    if (mRocketChatAccount) {
        if (auto r = mRocketChatAccount->room(value.toByteArray()); r) {
            return r->displayRoomName();
        }
    }
#endif
    return QStyledItemDelegate::displayText(value, locale);
}

bool ExploreDatabaseChatIdDelegate::helpEvent(QHelpEvent *event, QAbstractItemView *view, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (!event || !view)
        return false;

    if (event->type() == QEvent::ToolTip) {
        const QString tooltip = index.data(Qt::DisplayRole).toString();
        QToolTip::showText(event->globalPos(), tooltip);
        return true;
    }
    return QStyledItemDelegate::helpEvent(event, view, option, index);
}

#include "moc_exploredatabasechatiddelegate.cpp"
