/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "exampletexttoolpluginjob.h"
#include <QDebug>
using namespace Qt::Literals::StringLiterals;
ExampleTextToolPluginJob::ExampleTextToolPluginJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateTextToolPluginJob{parent}
{
}

ExampleTextToolPluginJob::~ExampleTextToolPluginJob() = default;

void ExampleTextToolPluginJob::start()
{
    qDebug() << " void ExampleTextToolPluginJob::start() ";
    if (!canStart()) {
        qWarning() << " Impossible to start ExampleTextToolPluginJob" << *this;
        deleteLater();
        return;
    }
    // TODO Need to implement job
    Q_EMIT finished(u"Temperature is 35°"_s, mMessageUuid, mChatId, mToolIdentifier);
    deleteLater();
}

#include "moc_exampletexttoolpluginjob.cpp"
