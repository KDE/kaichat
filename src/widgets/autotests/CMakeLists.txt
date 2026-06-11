# SPDX-FileCopyrightText: 2026 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

macro(add_kaichat_widgets_unittest _source)
    get_filename_component(_name ${_source} NAME_WE)
    ecm_add_test(${_source} ${_name}.h TEST_NAME ${_name}
        NAME_PREFIX "core-"
        LINK_LIBRARIES Qt::Test libkaichatwidgets
    )
endmacro()

add_kaichat_widgets_unittest(kaichatdatabaseselectchatlineedittest.cpp)
