# SPDX-FileCopyrightText: 2023-2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
macro(add_whatsnew_test _source)
    set(_test ${_source})
    get_filename_component(_name ${_source} NAME_WE)
    add_executable(
        ${_name}
        ${_test}
        ${_name}.h
    )
    add_test(NAME ${_name} COMMAND ${_name})
    ecm_mark_as_test(${_name})
    target_link_libraries(
        ${_name}
        Qt::Test
        libkaichatwidgets
    )
    set_target_properties(
        ${_name}
        PROPERTIES
            DISABLE_PRECOMPILE_HEADERS
                ON
    )
endmacro()

add_whatsnew_test(whatsnewdialogtest.cpp)
add_whatsnew_test(whatsnewwidgettest.cpp)
add_whatsnew_test(whatsnewmessagewidgettest.cpp)
add_whatsnew_test(whatsnewcomboboxwidgettest.cpp)
add_whatsnew_test(whatsnewinfotest.cpp)
