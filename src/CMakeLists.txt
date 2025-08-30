# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(core)
add_subdirectory(widgets)
add_subdirectory(apps)
add_subdirectory(plugins)

if(APPLE)
    set_target_properties(
        kaichat
        PROPERTIES
            MACOSX_BUNDLE_DISPLAY_NAME
                "KAIChat"
            MACOSX_BUNDLE_BUNDLE_NAME
                "KAIChat"
            MACOSX_BUNDLE_LONG_VERSION_STRING
                "KAIChat ${KAICHAT_VERSION}"
            MACOSX_BUNDLE_SHORT_VERSION_STRING
                "${KAICHAT_VERSION}"
            MACOSX_BUNDLE_BUNDLE_VERSION
                "${KAICHAT_VERSION}"
            MACOSX_BUNDLE_GUI_IDENTIFIER
                "org.kde.kaichat"
            MACOSX_BUNDLE_COPYRIGHT
                "2025 The KAIChat Developers"
    )
endif()

install(PROGRAMS data/org.kde.kaichat.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES data/org.kde.kaichat.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
install(FILES data/kaichat.notifyrc DESTINATION ${KDE_INSTALL_KNOTIFYRCDIR})
