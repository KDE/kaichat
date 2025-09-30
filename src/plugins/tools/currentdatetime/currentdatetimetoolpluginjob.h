/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QObject>
#include <TextAutoGenerateText/TextAutoGenerateTextToolPluginJob>
class CurrentDateTimeToolPluginJob : public TextAutoGenerateText::TextAutoGenerateTextToolPluginJob
{
    Q_OBJECT
public:
    explicit CurrentDateTimeToolPluginJob(QObject *parent = nullptr);
    ~CurrentDateTimeToolPluginJob() override;

    void start() override;
};
