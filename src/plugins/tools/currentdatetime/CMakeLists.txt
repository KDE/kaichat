# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

kcoreaddons_add_plugin(textautogeneratetext_currentdatetimeplugin INSTALL_NAMESPACE autogeneratetext/toolplugins)

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
)
target_link_libraries(textautogeneratetext_currentdatetimeplugin KF6::TextAutoGenerateText)
