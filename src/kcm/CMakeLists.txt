# SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_library(kcm_autogeneratetext MODULE)
target_sources(
    kcm_autogeneratetext
    PRIVATE
        kcmautogeneratetext.cpp
        kcmautogeneratetext.h
)

target_link_libraries(
    kcm_autogeneratetext
    PRIVATE
        Qt::Core
        KF6::KCMUtils
        KF6::TextAutoGenerateText
)

kcmutils_generate_desktop_file(kcm_autogeneratetext)

install(TARGETS kcm_autogeneratetext DESTINATION ${KDE_INSTALL_PLUGINDIR}/plasma/kcms/systemsettings_qwidgets)
