/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include <KCrash>
#include <KLocalizedString>
#include <QApplication>
#include <QCommandLineParser>

#include "config-kaichat.h"
#include "kaichatmainwindow.h"
#include <iostream>

#include <KAboutData>
#include <QIcon>

#include <KIconTheme>

#include <KStyleManager>

#if WITH_DBUS
#include <KDBusService>
#else
#include <KWindowSystem>
#include <QJsonArray>
#include <QJsonDocument>
#include <QWindow>
#include <kdsingleapplication.h>
#if !defined(Q_OS_WIN) && !defined(Q_OS_MACOS)
#include <private/qtx11extras_p.h>
#endif
#endif

using namespace Qt::Literals::StringLiterals;
int main(int argc, char *argv[])
{
    KIconTheme::initTheme();
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon::fromTheme(QStringLiteral("kaichat")));

    KStyleManager::initStyle();
    /*
#if !WITH_DBUS
    KDSingleApplication sapp;
#endif
*/
    KLocalizedString::setApplicationDomain("kaichat"_ba);

    KAboutData aboutData(QStringLiteral("kaichat"),
                         i18n("KAiChat"),
                         QStringLiteral(KAICHAT_VERSION),
                         i18n("Rocket Chat Client"),
                         KAboutLicense::GPL_V2,
                         i18n("Copyright © 2025 Laurent Montel"));
    aboutData.addAuthor(i18nc("@info:credit", "Laurent Montel"), i18n("Maintainer"), QStringLiteral("montel@kde.org"));
    aboutData.setOrganizationDomain("kde.org"_ba);
    aboutData.setProductName("kaichat"_ba);

    KAboutData::setApplicationData(aboutData);

    KCrash::initialize();
    QCommandLineParser parser;

    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

#if WITH_DBUS
    KDBusService service(KDBusService::Unique);
#else
    if (!sapp.isPrimaryInstance()) {
        QJsonDocument doc;

        QJsonObject obj;
        obj[QLatin1String("working_dir")] = QDir::currentPath();
        obj[QLatin1String("args")] = QJsonArray::fromStringList(app.arguments());
#if !defined(Q_OS_WIN) && !defined(Q_OS_MACOS)
        if (KWindowSystem::isPlatformWayland()) {
            obj[QLatin1String("xdg_activation_token")] = qEnvironmentVariable("XDG_ACTIVATION_TOKEN");
        } else if (KWindowSystem::isPlatformX11()) {
            obj[QLatin1String("startup_id")] = QString::fromUtf8(QX11Info::nextStartupId());
        }
#endif

        doc.setObject(obj);

        sapp.sendMessage(doc.toJson(QJsonDocument::Compact));
        return 0;
    }
#endif
    auto mw = new KAIChatMainWindow();
#if 0
#if WITH_DBUS
    QObject::connect(&service, &KDBusService::activateRequested, mw, &RuqolaMainWindow::slotActivateRequested);
#else
    QApplication::connect(&sapp, &KDSingleApplication::messageReceived, &app, [mw](const QByteArray &messageData) {
        QJsonDocument doc = QJsonDocument::fromJson(messageData);
        QJsonObject message = doc.object();

#if !defined(Q_OS_WIN) && !defined(Q_OS_MACOS)
        if (KWindowSystem::isPlatformWayland()) {
            qputenv("XDG_ACTIVATION_TOKEN", message[QLatin1String("xdg_activation_token")].toString().toUtf8());
        } else if (KWindowSystem::isPlatformX11()) {
            QX11Info::setNextStartupId(message[QLatin1String("startup_id")].toString().toUtf8());
        }
#endif
        QStringList arguments;

        const auto argumentsJson = message[QLatin1String("args")].toArray();
        for (const QJsonValue &val : argumentsJson) {
            arguments << val.toString();
        }

        mw->slotActivateRequested(arguments, message[QLatin1String("working_dir")].toString());
    });
#endif
    mw->parseCommandLine(&parser);
#endif
    mw->show();
    const int val = app.exec();
    return val;
}
