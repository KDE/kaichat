# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
add_subdirectory(icons)

add_library(libkaichatwidgets)

target_sources(libkaichatwidgets PRIVATE
    kaichatmainwindow.h
    kaichatmainwindow.cpp
    kaichatcentralwidget.h
    kaichatcentralwidget.cpp

    kaichatnotificatifieritem.h
    kaichatnotificatifieritem.cpp

    libkaichatwidgets_private_export.h
    kaichatwidgets.qrc

    kaichatconfiguresettingsdialog.h
    kaichatconfiguresettingsdialog.cpp

    kaichatconfiguregeneralwidget.h
    kaichatconfiguregeneralwidget.cpp
)

kconfig_add_kcfg_files(libkaichatwidgets settings/kaichatglobalconfig.kcfgc)


if(COMPILE_WITH_UNITY_CMAKE_SUPPORT)
    set_target_properties(libkaichatwidgets PROPERTIES UNITY_BUILD ON)
endif()
generate_export_header(libkaichatwidgets BASE_NAME libkaichatwidgets)

target_link_libraries(libkaichatwidgets
    Qt::Gui
    Qt::Widgets
    KF6::XmlGui
    KF6::I18n
    KF6::TextAutoGenerateText
    KF6::WindowSystem
    KF6::StatusNotifierItem
    libkaichatcore
)

set_target_properties(libkaichatwidgets
    PROPERTIES OUTPUT_NAME kaichatwidgets VERSION ${KAICHAT_LIB_VERSION} SOVERSION ${KAICHAT_LIB_VERSION}
)

install(TARGETS libkaichatwidgets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} LIBRARY NAMELINK_SKIP)
