# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)
set(KAICHAT_VERSION "0.1")
project(kaichat VERSION ${KAICHAT_VERSION})

set(KAICHAT_LIB_VERSION "${KAICHAT_VERSION}")

set(QT_REQUIRED_VERSION "6.8.0")
set(KF_MIN_VERSION "6.13.0")

set(ECM_VERSION ${KF_MIN_VERSION})
find_package(ECM ${ECM_VERSION} REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH})
include(FeatureSummary)
include(KDEGitCommitHooks)
include(KDEClangFormat)
file(GLOB_RECURSE ALL_CLANG_FORMAT_SOURCE_FILES *.cpp *.h *.c)
kde_clang_format(${ALL_CLANG_FORMAT_SOURCE_FILES})
include(ECMAddAppIcon)
include(ECMInstallIcons)
include(KDEInstallDirs)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(KDECMakeSettings)
include(ECMAddTests)
include(ECMQtDeclareLoggingCategory)
include(GenerateExportHeader)
include(ECMDeprecationSettings)
include(ECMCheckOutboundLicense)

set(KTEXTADDONS_MIN_VERSION "1.5.4")
# Remove it when next 1.6.0 KTEXTADDONS_MIN_VERSION
set(KTEXTADDONS_WITH_TEXTAUTOGENERATETEXT_VERSION "1.5.64")

find_package(Qt6 ${QT_REQUIRED_VERSION} REQUIRED NO_MODULE COMPONENTS Widgets)
find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    Config
    I18n
    WidgetsAddons
    XmlGui
    IconThemes
    Crash
)

find_package(KF6TextAutogenerateText ${KTEXTADDONS_WITH_TEXTAUTOGENERATETEXT_VERSION} CONFIG)
set_package_properties(KF6TextAutogenerateText PROPERTIES
    TYPE REQUIRED
    PURPOSE "Required for building AI plugins support"
    DESCRIPTION "Use AI plugin"
)

add_definitions(-DTRANSLATION_DOMAIN="kaichat")
add_definitions(-DQT_NO_CONTEXTLESS_CONNECT)
ecm_set_disabled_deprecation_versions(QT 6.9.0
    KF 6.13.0
)

set(KAICHAT_LIB_SOVERSION "0")

if(BUILD_TESTING)
    add_definitions(-DBUILD_TESTING)
endif()

add_subdirectory( src )

kde_configure_git_pre_commit_hook(CHECKS CLANG_FORMAT)
ki18n_install(po)
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

file(GLOB_RECURSE ALL_SOURCE_FILES src/quickapps/*.cpp src/quickapps/*.h src/core/*.cpp src/core/*.h src/apps/*.h src/apps/*.cpp src/widgets/*.cpp src/widgets/*.h)
ecm_check_outbound_license(LICENSES GPL-2.0-only  FILES ${ALL_SOURCE_FILES})
