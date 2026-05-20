# SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
add_test(
    NAME kaichat-self-test
    COMMAND
        kaichat --self-test
)
