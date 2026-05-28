/*
 * SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#pragma once
#include "config-kaichat.h"
#include "libkaichatwidgets_private_export.h"
#include <KAboutData>
#include <QWidget>
#include <TextAutoGenerateText/TextAutoGenerateMessage>
namespace TextAutoGenerateText
{
class TextAutoGenerateStackWidget;
class TextAutoGenerateManager;
}
class LIBKAICHATWIDGETS_TESTS_EXPORT KAIChatCentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KAIChatCentralWidget(
#if WHATSNEWSNGSUPPORT
        const QList<KAboutRelease> &releases,
#endif
        TextAutoGenerateText::TextAutoGenerateManager *manager,
        QWidget *parent = nullptr);
    ~KAIChatCentralWidget() override;

    void showArchive(bool checked);
    void searchText();

    [[nodiscard]] QList<TextAutoGenerateText::TextAutoGenerateMessage> messagesFromCurrentChat() const;

    [[nodiscard]] QString chatCurrentTitle() const;

    [[nodiscard]] QList<KAboutRelease> releases() const;

private:
    TextAutoGenerateText::TextAutoGenerateStackWidget *const mTextAutogenerateWidget;
    TextAutoGenerateText::TextAutoGenerateManager *const mManager;
#if WHATSNEWSNGSUPPORT
    QList<KAboutRelease> mReleases;
#endif
};
