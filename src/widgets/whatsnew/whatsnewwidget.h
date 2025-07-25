/*
   SPDX-FileCopyrightText: 2023-2025 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once
#include "libkaichatwidgets_private_export.h"
#include "whatsnewcomboboxwidget.h"
#include "whatsnewinfo.h"
#include <QWidget>
class QTextBrowser;
class LIBKAICHATWIDGETS_TESTS_EXPORT WhatsNewWidget : public QWidget
{
    Q_OBJECT
public:
    explicit WhatsNewWidget(QWidget *parent = nullptr);
    ~WhatsNewWidget() override;

    void updateInformations();

private:
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT int currentVersion() const;
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT QString generateStartEndHtml(const QString &str) const;
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT QString importantChangeStr() const;
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT QString featuresChangeStr() const;
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT QString bugFixingChangeStr() const;
    LIBKAICHATWIDGETS_NO_EXPORT void slotVersionChanged(int i);
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT QString createVersionInformation(const WhatsNewInfo &info);
    LIBKAICHATWIDGETS_NO_EXPORT void fillTranslations();
    [[nodiscard]] LIBKAICHATWIDGETS_NO_EXPORT QString generateVersionHeader(int type) const;
    LIBKAICHATWIDGETS_NO_EXPORT void fillComboBox();

    QList<WhatsNewInfo> mWhatsNewInfo;
    QTextBrowser *const mLabelInfo;
    WhatsNewComboBoxWidget *const mWhatsNewComboBoxWidget;
};
