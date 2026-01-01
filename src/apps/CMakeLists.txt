# SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

include(ECMAddAppIcon)

add_executable(
    kaichat
    main.cpp
    kaichat.qrc
)

if(COMPILE_WITH_UNITY_CMAKE_SUPPORT)
    set_target_properties(
        kaichat
        PROPERTIES
            UNITY_BUILD
                ON
    )
endif()

target_link_libraries(
    kaichat
    KF6::Crash
    KF6::XmlGui
    KF6::IconThemes
    KF6::I18n
    KF6::CoreAddons
    libkaichatwidgets
)

if(USE_DBUS)
    target_link_libraries(kaichat KF6::DBusAddons)
else()
    target_link_libraries(kaichat KDAB::kdsingleapplication)
    if(NOT WIN32 AND NOT APPLE)
        if(Qt6Gui_VERSION VERSION_GREATER_EQUAL "6.10.0")
            find_package(Qt6GuiPrivate ${QT_REQUIRED_VERSION} REQUIRED NO_MODULE)
        endif()
        target_link_libraries(kaichat Qt::GuiPrivate)
    endif()
endif()

#file(GLOB_RECURSE KAICHAT_ICONS "${PROJECT_SOURCE_DIR}/src/widgets/icons/*-apps-kaichat.png")
#ecm_add_app_icon(appIcons ICONS "${KAICHAT_ICONS}")
#target_sources(kaichat PRIVATE ${appIcons})

install(
    TARGETS
        kaichat
        ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}
)
