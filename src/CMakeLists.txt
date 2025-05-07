# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(apps)

install(PROGRAMS data/org.kde.kaichat.desktop DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES data/org.kde.kaichat.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
