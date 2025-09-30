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
    mToolNameId = "current_date_time_tool"_ba;
    {
        TextAutoGenerateText::TextAutoGenerateTextToolPluginProperty prop;
        prop.setDescription(kli18n("The Current Date Time"));
        prop.setName(u"currentdatetime"_s);
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
    return i18n("Use this tools to get current date time");
}

void CurrentDateTimeToolPlugin::showConfigureDialog(QWidget *parent)
{
    auto dlg = CurrentDateTimeToolPluginDialog(this, parent);
    dlg.exec();
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
