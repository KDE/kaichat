/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"
#include <QAbstractListModel>

class LIBKAICHATCORE_EXPORT KAIChatCompletionListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    struct CompletionInfo {
        QString chatName;
        QByteArray chatId;
        [[nodiscard]] bool isValid() const
        {
            return !chatName.isEmpty() && !chatId.isEmpty();
        }
    };

    enum CompletionRoles : uint16_t {
        ChatUuid = Qt::UserRole + 1,
        ChatName,
    };

    explicit KAIChatCompletionListModel(QObject *parent = nullptr);
    ~KAIChatCompletionListModel() override;

    [[nodiscard]] int rowCount(const QModelIndex & = {}) const override;
    /*!
     */
    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;

    [[nodiscard]] QList<CompletionInfo> completionInfos() const;
    void setCompletionInfos(const QList<CompletionInfo> &newCompletionInfos);

private:
    LIBKAICHATCORE_NO_EXPORT void clear();
    QList<CompletionInfo> mCompletionInfos;
};
