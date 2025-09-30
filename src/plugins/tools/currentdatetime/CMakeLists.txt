# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

kcoreaddons_add_plugin(textautogeneratetext_currentdatetimeplugin INSTALL_NAMESPACE autogeneratetext/toolplugins)

ecm_qt_declare_logging_category(textautogeneratetext_currentdatetimeplugin HEADER kaichat_currentdatetimeplugin_debug.h IDENTIFIER KAICHAT_CURRENTDATETIME_LOG
    CATEGORY_NAME org.kde.kaichat_currentdatetimeplugin DESCRIPTION "kaichat (currentdatetimeplugin)" EXPORT KAICHAT
)

target_sources(
    textautogeneratetext_currentdatetimeplugin
    PRIVATE
        currentdatetimetoolplugin.h
        currentdatetimetoolplugin.cpp
        currentdatetimetoolplugindialog.h
        currentdatetimetoolplugindialog.cpp
        currentdatetimetoolpluginwidget.h
        currentdatetimetoolpluginwidget.cpp
        currentdatetimetoolpluginjob.h
        currentdatetimetoolpluginjob.cpp
        currentdatetimetoolpluginutils.h
        currentdatetimetoolpluginutils.cpp
)
target_link_libraries(textautogeneratetext_currentdatetimeplugin KF6::TextAutoGenerateText)
