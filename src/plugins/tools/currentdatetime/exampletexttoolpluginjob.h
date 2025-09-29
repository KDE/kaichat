/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QObject>
#include <TextAutoGenerateText/TextAutoGenerateTextToolPluginJob>
class ExampleTextToolPluginJob : public TextAutoGenerateText::TextAutoGenerateTextToolPluginJob
{
    Q_OBJECT
public:
    explicit ExampleTextToolPluginJob(QObject *parent = nullptr);
    ~ExampleTextToolPluginJob() override;

    void start() override;
};
