# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)
set(KAICHAT_VERSION "0.2")
project(kaichat VERSION ${KAICHAT_VERSION})

set(KAICHAT_LIB_VERSION "${KAICHAT_VERSION}")

# Do NOT add quote
set(KAICHAT_DEV_VERSION alpha)
# add an extra space
if(DEFINED KAICHAT_DEV_VERSION)
    set(KAICHAT_DEV_VERSION " ${KAICHAT_DEV_VERSION}")
endif()

set(KAICHAT_VERSION_STRING "${KAICHAT_VERSION}${KAICHAT_DEV_VERSION}")


set(QT_REQUIRED_VERSION "6.8.0")
set(KF_MIN_VERSION "6.13.0")
set(CMAKE_CXX_STANDARD 20)

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
set(KTEXTADDONS_WITH_TEXTAUTOGENERATETEXT_VERSION "1.5.73")

find_package(Qt6 ${QT_REQUIRED_VERSION} REQUIRED NO_MODULE COMPONENTS Widgets)
find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    Config
    I18n
    WidgetsAddons
    XmlGui
    IconThemes
    Crash
    WindowSystem
)

find_package(KF6StatusNotifierItem ${KF_MIN_VERSION} REQUIRED)

find_package(KF6TextAutoGenerateText ${KTEXTADDONS_WITH_TEXTAUTOGENERATETEXT_VERSION} CONFIG)
set_package_properties(KF6TextAutoGenerateText PROPERTIES
    TYPE REQUIRED
    PURPOSE "Required for building AI plugins support"
    DESCRIPTION "Use AI plugin"
)

add_definitions(-DTRANSLATION_DOMAIN="kaichat")
add_definitions(-DQT_NO_CONTEXTLESS_CONNECT)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
ecm_set_disabled_deprecation_versions(QT 6.9.0
    KF 6.14.0
)

set(KAICHAT_LIB_SOVERSION "0")

if(BUILD_TESTING)
    find_package(Qt6 ${REQUIRED_QT_VERSION} REQUIRED COMPONENTS Test)
    add_definitions(-DBUILD_TESTING)
endif()

# shall we use DBus?
# enabled per default on Linux & BSD systems
set(USE_DBUS_DEFAULT OFF)
if(UNIX AND NOT APPLE AND NOT HAIKU)
    set(USE_DBUS_DEFAULT ON)
endif()

option(USE_DBUS "Build components using DBus" ${USE_DBUS_DEFAULT})
if(USE_DBUS)
   set(WITH_DBUS TRUE)
   find_package(KF6DBusAddons ${KF_MIN_VERSION} CONFIG REQUIRED)
endif()

if (NOT USE_DBUS)
    find_package(KDSingleApplication-qt6 CONFIG REQUIRED)
endif()


configure_file(config-kaichat.h.in ${CMAKE_CURRENT_BINARY_DIR}/config-kaichat.h)

add_subdirectory( src )

kde_configure_git_pre_commit_hook(CHECKS CLANG_FORMAT)
ki18n_install(po)
file(GLOB_RECURSE ALL_SOURCE_FILES src/apps/*.h src/apps/*.cpp src/widgets/*.cpp src/widgets/*.h)
ecm_check_outbound_license(LICENSES GPL-2.0-only  FILES ${ALL_SOURCE_FILES})

ecm_qt_install_logging_categories(
    EXPORT KAICHAT
    FILE kaichat.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

