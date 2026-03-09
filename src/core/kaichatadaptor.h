/*
 * SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */
#pragma once
#include "libkaichatcore_export.h"
#include <QDBusAbstractAdaptor>
#include <TextAutoGenerateText/TextAutoGenerateManager>

class LIBKAICHATCORE_EXPORT KAIChatAdaptor : public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.kaichat.Application")

public:
    explicit KAIChatAdaptor(TextAutoGenerateText::TextAutoGenerateManager *manager, QObject *parent = nullptr);
    ~KAIChatAdaptor() override;

public Q_SLOTS:
    void showArchived(bool b);
    void createNewChat(const QString &title);
    QStringList chatsList();
    void switchToChat(const QString &chatName);
    void switchToChatId(const QByteArray &chatId);
    void ask(const QString &chatId);

private:
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
};
