# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

macro(add_kaichat_core_unittest _source)
    get_filename_component(_name ${_source} NAME_WE)
    ecm_add_test(${_source} ${_name}.h TEST_NAME ${_name}
        NAME_PREFIX "core-"
        LINK_LIBRARIES Qt::Test libkaichatcore
    )
endmacro()
add_kaichat_core_unittest(kaichatexportchatjobtest.cpp)
add_kaichat_core_unittest(kaichatimportchatjobtest.cpp)
add_kaichat_core_unittest(kaichatexportchatasbasejobtest.cpp)
add_kaichat_core_unittest(kaichatexportchatasjsonjobtest.cpp)
