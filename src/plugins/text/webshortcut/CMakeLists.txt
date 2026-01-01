# SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

kcoreaddons_add_plugin(kaichat_webshortcuttextplugin INSTALL_NAMESPACE autogeneratetext/textplugins)

target_sources(
    kaichat_webshortcuttextplugin
    PRIVATE
        webshortcuttextinterface.cpp
        webshortcuttextplugin.cpp
        webshortcuttextinterface.h
        webshortcuttextplugin.h
)
target_link_libraries(
    kaichat_webshortcuttextplugin
    libkaichatwidgets
    KF6::CoreAddons
    KF6::KIOWidgets
)
