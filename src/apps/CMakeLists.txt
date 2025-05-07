# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

include(ECMAddAppIcon)

add_executable(kaitalk main.cpp)

target_link_libraries(kaitalk
    KF6::Crash
    KF6::XmlGui
    KF6::IconThemes
    KF6::I18n
)
if (0)
if(USE_DBUS)
    target_link_libraries(kaitalk KF6::DBusAddons)
else()
    target_link_libraries(kaitalk KDAB::kdsingleapplication)
    if (NOT WIN32 AND NOT APPLE)
        target_link_libraries(kaitalk Qt::GuiPrivate)
    endif()
endif()
endif()

#file(GLOB_RECURSE RUQOLA_ICONS "${PROJECT_SOURCE_DIR}/src/icons/*-apps-ruqola.png")
#ecm_add_app_icon(appIcons ICONS "${RUQOLA_ICONS}")
#target_sources(ruqola PRIVATE ${appIcons})

install(TARGETS kaitalk ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
