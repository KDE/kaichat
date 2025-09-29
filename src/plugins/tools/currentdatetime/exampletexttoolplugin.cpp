/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "exampletexttoolplugin.h"
#include "exampletexttoolplugindialog.h"
#include "exampletexttoolpluginjob.h"
#include <KPluginFactory>
#include <QPointer>
K_PLUGIN_CLASS_WITH_JSON(ExampleTextToolPlugin, "textautogeneratetext_exampleplugin.json")

using namespace Qt::Literals::StringLiterals;
ExampleTextToolPlugin::ExampleTextToolPlugin(QObject *parent, const QVariantList &)
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

ExampleTextToolPlugin::~ExampleTextToolPlugin() = default;

void ExampleTextToolPlugin::executeTool()
{
    // TODO
}

QString ExampleTextToolPlugin::displayName() const
{
    // Don't translate it
    return u"Ask Weather Report"_s;
}

QString ExampleTextToolPlugin::description() const
{
    // Don't translate it
    return u"Use this tools, only on meteo. Get the current weather for a city"_s;
}

void ExampleTextToolPlugin::showConfigureDialog(QWidget *parent)
{
    QPointer<ExampleTextToolPluginDialog> dlg = new ExampleTextToolPluginDialog(this, parent);
    if (dlg->exec()) {
        // Nothing => just display info
    }
    delete dlg;
}

void ExampleTextToolPlugin::callTools(const QByteArray &chatId,
                                      const QByteArray &uuid,
                                      const QList<TextAutoGenerateText::TextAutoGenerateReply::ToolCallArgumentInfo> &info)
{
    for (const auto &i : info) {
        ExampleTextToolPluginJob *job = new ExampleTextToolPluginJob(this);
        job->setToolArguments(i.toolCallArgument);
        job->setChatId(chatId);
        job->setMessageUuid(uuid);
        job->setToolIdentifier(i.toolName);
        connect(job,
                &ExampleTextToolPluginJob::finished,
                this,
                [this](const QString &str, const QByteArray &messageUuid, const QByteArray &chatId, const QByteArray &toolIdentifier) {
                    Q_EMIT finished(str, messageUuid, chatId, toolIdentifier);
                    qDebug() << " ExampleTextToolPluginJob::finished: " << str;
                });
        job->start();
    }
}

#include "exampletexttoolplugin.moc"
#include "moc_exampletexttoolplugin.cpp"
