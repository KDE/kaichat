# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

kcoreaddons_add_plugin(kaichat_sharetextplugin INSTALL_NAMESPACE autogeneratetext/textplugins)

target_sources(
    kaichat_sharetextplugin
    PRIVATE
        sharetextinterface.cpp
        sharetextplugin.cpp
        sharetextinterface.h
        sharetextplugin.h
        purposemenuwidget.cpp
        purposemenuwidget.h
)
target_link_libraries(
    kaichat_sharetextplugin
    libkaichatwidgets
    KF6::Purpose
    KF6::PurposeWidgets
)
