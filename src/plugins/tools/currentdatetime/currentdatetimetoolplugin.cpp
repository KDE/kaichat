/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "currentdatetimetoolplugin.h"
#include "currentdatetimetoolplugindialog.h"
#include "currentdatetimetoolpluginjob.h"
#include "currentdatetimetoolpluginutils.h"
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
        prop.setName(CurrentDateTimeToolPluginUtils::currentDateTimePropertyName());
        prop.setTypeElements({CurrentDateTimeToolPluginUtils::convertDateTimeEnumToString(CurrentDateTimeToolPluginUtils::Date),
                              CurrentDateTimeToolPluginUtils::convertDateTimeEnumToString(CurrentDateTimeToolPluginUtils::Time),
                              CurrentDateTimeToolPluginUtils::convertDateTimeEnumToString(CurrentDateTimeToolPluginUtils::DateTime)});
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
    return i18n("Use this tool to get current date time");
}

void CurrentDateTimeToolPlugin::showConfigureDialog(QWidget *parent)
{
    auto dlg = CurrentDateTimeToolPluginDialog(this, parent);
    dlg.exec();
}

TextAutoGenerateText::TextAutoGenerateTextToolPluginJob *CurrentDateTimeToolPlugin::callTool()
{
    return new CurrentDateTimeToolPluginJob(this);
}

QString CurrentDateTimeToolPlugin::iconName() const
{
    return u"preferences-system-time"_s;
}

int CurrentDateTimeToolPlugin::order() const
{
    return 15;
}

#include "currentdatetimetoolplugin.moc"
#include "moc_currentdatetimetoolplugin.cpp"
