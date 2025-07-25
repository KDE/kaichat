# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_library(libkaichatcore)

ecm_qt_declare_logging_category(libkaichatcore_debug_SRCS HEADER kaichat_core_debug.h IDENTIFIER KAICHAT_CORE_LOG
    CATEGORY_NAME org.kde.kaichat_core DESCRIPTION "kaichat (core lib)" EXPORT KAICHAT
)

target_sources(
    libkaichatcore
    PRIVATE
        kaichatexportchatjob.h
        kaichatexportchatjob.cpp
        kaichatimportchatjob.h
        kaichatimportchatjob.cpp
        kaichatexportchatasmardownjob.h
        kaichatexportchatasmardownjob.cpp
        kaichatexportchatastextjob.h
        kaichatexportchatastextjob.cpp
        ${libkaichatcore_debug_SRCS}
)

if(COMPILE_WITH_UNITY_CMAKE_SUPPORT)
    set_target_properties(
        libkaichatcore
        PROPERTIES
            UNITY_BUILD
                ON
    )
endif()
generate_export_header(libkaichatcore BASE_NAME libkaichatcore)

target_link_libraries(
    libkaichatcore
    PUBLIC
        KF6::TextAutoGenerateText
    PRIVATE
        Qt6::Core
        KF6::I18n
)
set_target_properties(
    libkaichatcore
    PROPERTIES
        OUTPUT_NAME
            kaichatcore
        VERSION
            ${KAICHAT_LIB_VERSION}
        SOVERSION
            ${KAICHAT_LIB_VERSION}
)

install(
    TARGETS
        libkaichatcore
        ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}
    LIBRARY
        NAMELINK_SKIP
)

if(BUILD_TESTING)
    add_subdirectory(autotests)
endif()
