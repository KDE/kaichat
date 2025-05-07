# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(libkaichatwidgets)

target_sources(libkaichatwidgets PRIVATE
    kaichatmainwindow.h
    kaichatmainwindow.cpp
    kaichatcentralwidget.h
    kaichatcentralwidget.cpp

    libkaichatwidgets_private_export.h
    kaichatwidgets.qrc
)


if(COMPILE_WITH_UNITY_CMAKE_SUPPORT)
    set_target_properties(libkaichatwidgets PROPERTIES UNITY_BUILD ON)
endif()
generate_export_header(libkaichatwidgets BASE_NAME libkaichatwidgets)

target_link_libraries(libkaichatwidgets
    Qt::Gui
    Qt::Widgets
    KF6::XmlGui
)

set_target_properties(libkaichatwidgets
    PROPERTIES OUTPUT_NAME kaichatwidgets VERSION ${KAICHAT_LIB_VERSION} SOVERSION ${KAICHAT_LIB_VERSION}
)

install(TARGETS libkaichatwidgets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS} LIBRARY NAMELINK_SKIP)
