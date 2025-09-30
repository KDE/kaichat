/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "currentdatetimetoolplugin.h"
#include "currentdatetimetoolplugindialog.h"
#include "currentdatetimetoolpluginjob.h"
#include <KLocalizedString>
#include <KPluginFactory>
#include <QPointer>
K_PLUGIN_CLASS_WITH_JSON(CurrentDateTimeToolPlugin, "textautogeneratetext_currentdatetimeplugin.json")

using namespace Qt::Literals::StringLiterals;
CurrentDateTimeToolPlugin::CurrentDateTimeToolPlugin(QObject *parent, const QVariantList &)
    : TextAutoGenerateTextToolPlugin{parent}
{
    mToolNameId = "example_tool"_ba;
    {
        TextAutoGenerateText::TextAutoGenerateTextToolPluginProperty prop;
        prop.setDescription(kli18n("The name of the city"));
        prop.setName(u"city"_s);
        mProperties.append(prop);
    }
}

CurrentDateTimeToolPlugin::~CurrentDateTimeToolPlugin() = default;

QString CurrentDateTimeToolPlugin::displayName() const
{
    return i18n("Get Current Date Time");
}

QString CurrentDateTimeToolPlugin::description() const
{
    // Don't translate it
    return u"Use this tools, only on meteo. Get the current weather for a city"_s;
}

void CurrentDateTimeToolPlugin::showConfigureDialog(QWidget *parent)
{
    QPointer<CurrentDateTimeToolPluginDialog> dlg = new CurrentDateTimeToolPluginDialog(this, parent);
    if (dlg->exec()) {
        // Nothing => just display info
    }
    delete dlg;
}

void CurrentDateTimeToolPlugin::callTools(const QByteArray &chatId,
                                          const QByteArray &uuid,
                                          const QList<TextAutoGenerateText::TextAutoGenerateReply::ToolCallArgumentInfo> &info)
{
    for (const auto &i : info) {
        CurrentDateTimeToolPluginJob *job = new CurrentDateTimeToolPluginJob(this);
        job->setToolArguments(i.toolCallArgument);
        job->setChatId(chatId);
        job->setMessageUuid(uuid);
        job->setToolIdentifier(i.toolName);
        connect(job,
                &CurrentDateTimeToolPluginJob::finished,
                this,
                [this](const QString &str, const QByteArray &messageUuid, const QByteArray &chatId, const QByteArray &toolIdentifier) {
                    Q_EMIT finished(str, messageUuid, chatId, toolIdentifier);
                    // qDebug() << " CurrentDateTimeToolPluginJob::finished: " << str;
                });
        job->start();
    }
}

#include "currentdatetimetoolplugin.moc"
#include "moc_currentdatetimetoolplugin.cpp"
