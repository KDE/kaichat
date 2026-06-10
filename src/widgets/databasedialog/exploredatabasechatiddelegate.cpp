/*
   SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "exploredatabasechatiddelegate.h"
#include <QHelpEvent>
#include <QToolTip>
#include <TextAutoGenerateText/TextAutoGenerateChatsModel>
#include <TextAutoGenerateText/TextAutoGenerateManager>

ExploreDatabaseChatIdDelegate::ExploreDatabaseChatIdDelegate(TextAutoGenerateText::TextAutoGenerateManager *manager, QObject *parent)
    : QStyledItemDelegate{parent}
    , mManager(manager)
{
}

ExploreDatabaseChatIdDelegate::~ExploreDatabaseChatIdDelegate() = default;

QString ExploreDatabaseChatIdDelegate::displayText(const QVariant &value, const QLocale &locale) const
{
    if (mManager) {
        return mManager->textAutoGenerateChatsModel()->title(value.toByteArray());
    }
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
