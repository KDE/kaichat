# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

include(ECMAddAppIcon)

add_executable(
    kaichat
    main.cpp
    kaichat.qrc
)

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
        target_link_libraries(kaichat Qt::GuiPrivate)
    endif()
endif()

file(GLOB_RECURSE KAICHAT_ICONS "${PROJECT_SOURCE_DIR}/src/widgets/icons/*-apps-kaichat.png")
ecm_add_app_icon(appIcons ICONS "${KAICHAT_ICONS}")
target_sources(kaichat PRIVATE ${appIcons})

install(
    TARGETS
        kaichat
        ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}
)
