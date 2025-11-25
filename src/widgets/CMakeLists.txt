# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause
add_subdirectory(icons)

add_library(libkaichatwidgets)
ecm_qt_declare_logging_category(libkaichatwidgets HEADER kaichat_widget_debug.h IDENTIFIER KAICHAT_WIDGET_LOG
    CATEGORY_NAME org.kde.kaichat_widget DESCRIPTION "kaichat (widget lib)" EXPORT KAICHAT
)

target_sources(
    libkaichatwidgets
    PRIVATE
        kaichatmainwindow.h
        kaichatmainwindow.cpp
        kaichatcentralwidget.h
        kaichatcentralwidget.cpp
        kaichatnotificatifieritem.h
        kaichatnotificatifieritem.cpp
        kaichatchangefontsizemenu.h
        kaichatchangefontsizemenu.cpp
        libkaichatwidgets_private_export.h
        kaichatwidgets.qrc
        kaichatconfiguresettingsdialog.h
        kaichatconfiguresettingsdialog.cpp
        kaichatconfiguregeneralwidget.h
        kaichatconfiguregeneralwidget.cpp
        kaichatconfigurefontwidget.cpp
        kaichatconfigurespellcheckingwidget.cpp
        kaichatconfigurefontwidget.h
        kaichatconfigurespellcheckingwidget.h
        kaichatexportmenu.h
        kaichatexportmenu.cpp
        kaichatconfigureinstanceswidget.h
        kaichatconfigureinstanceswidget.cpp
        kaichatutils.h
        kaichatutils.cpp
        whatsnew/whatsnewdialog.h
        whatsnew/whatsnewdialog.cpp
        whatsnew/whatsnewwidget.h
        whatsnew/whatsnewwidget.cpp
        whatsnew/whatsnewmessagewidget.h
        whatsnew/whatsnewmessagewidget.cpp
        whatsnew/whatsnewcomboboxwidget.h
        whatsnew/whatsnewcomboboxwidget.cpp
        whatsnew/whatsnewtranslationbase.h
        whatsnew/whatsnewtranslationbase.cpp
        whatsnew/whatsnewinfo.h
        whatsnew/whatsnewinfo.cpp
        whatsnew/whatsnewtranslations.h
        whatsnew/whatsnewtranslations.cpp
        verifynewversionwidget/verifynewversionwidget.h
        verifynewversionwidget/verifynewversionwidget.cpp
        verifynewversionwidget/verifynewversiondialog.h
        verifynewversionwidget/verifynewversiondialog.cpp
        verifynewversionwidget/verifynewversionwidgetaction.cpp
        verifynewversionwidget/verifynewversionwidgetaction.h
        needupdateversion/needupdateversionwidget.h
        needupdateversion/needupdateversionwidget.cpp
        needupdateversion/needupdateversionutils.h
        needupdateversion/needupdateversionutils.cpp
        needupdateversion/needupdateparsehtmljob.h
        needupdateversion/needupdateparsehtmljob.cpp
        needupdateversion/needupdateparsehtmlutil.h
        needupdateversion/needupdateparsehtmlutil.cpp
        needupdateversion/needupdatecheckexistingnewversionjob.h
        needupdateversion/needupdatecheckexistingnewversionjob.cpp
)

kconfig_add_kcfg_files(libkaichatwidgets settings/kaichatglobalconfig.kcfgc)

if(COMPILE_WITH_UNITY_CMAKE_SUPPORT)
    set_target_properties(
        libkaichatwidgets
        PROPERTIES
            UNITY_BUILD
                ON
    )
endif()
generate_export_header(libkaichatwidgets BASE_NAME libkaichatwidgets)

target_link_libraries(
    libkaichatwidgets
    Qt::Gui
    Qt::Widgets
    KF6::XmlGui
    KF6::I18n
    KF6::WindowSystem
    KF6::StatusNotifierItem
    KF6::KIOCore
    KF6::SonnetUi
    KF6::Notifications
    KF6::NotifyConfig
    libkaichatcore
    KF6::TextAddonsWidgets
)
set_target_properties(
    libkaichatwidgets
    PROPERTIES
        OUTPUT_NAME
            kaichatwidgets
        VERSION
            ${KAICHAT_LIB_VERSION}
        SOVERSION
            ${KAICHAT_LIB_SOVERSION}
)

install(
    TARGETS
        libkaichatwidgets
        ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}
    LIBRARY
        NAMELINK_SKIP
)

if(BUILD_TESTING)
    add_subdirectory(whatsnew/autotests)
    add_subdirectory(needupdateversion/autotests)
    add_subdirectory(needupdateversion/tests)
    add_subdirectory(verifynewversionwidget/autotests)
endif()
