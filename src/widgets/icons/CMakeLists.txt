# SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
set(icons
    16-apps-kaichat.png
    22-apps-kaichat.png
    24-apps-kaichat.png
    32-apps-kaichat.png
    48-apps-kaichat.png
    sc-apps-kaichat.svg
)

set(all_icons ${icons})

ecm_install_icons(ICONS ${all_icons}
    DESTINATION ${KDE_INSTALL_ICONDIR}
    THEME hicolor
)
