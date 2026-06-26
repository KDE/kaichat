/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "kaichatcompletionlistmodel.h"

KAIChatCompletionListModel::KAIChatCompletionListModel(QObject *parent)
    : QAbstractListModel{parent}
{
}

KAIChatCompletionListModel::~KAIChatCompletionListModel() = default;

int KAIChatCompletionListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0; // flat model
    }
    return mCompletionInfos.count();
}

QVariant KAIChatCompletionListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= mCompletionInfos.count()) {
        return {};
    }
    const auto &info = mCompletionInfos[index.row()];
    switch (role) {
    case Qt::DisplayRole:
    case CompletionRoles::ChatName:
        return info.chatName;
    case CompletionRoles::ChatUuid:
        return info.chatId;
    default:
        break;
    }
    return {};
}

QList<KAIChatCompletionListModel::CompletionInfo> KAIChatCompletionListModel::completionInfos() const
{
    return mCompletionInfos;
}

void KAIChatCompletionListModel::setCompletionInfos(const QList<CompletionInfo> &newCompletionInfos)
{
    clear();
    if (!newCompletionInfos.isEmpty()) {
        beginInsertRows(QModelIndex(), 0, newCompletionInfos.count() - 1);
        mCompletionInfos = newCompletionInfos;
        endInsertRows();
    }
}

void KAIChatCompletionListModel::clear()
{
    if (!mCompletionInfos.isEmpty()) {
        beginResetModel();
        mCompletionInfos.clear();
        endResetModel();
    }
}

#include "moc_kaichatcompletionlistmodel.cpp"
