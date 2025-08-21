/*
 * SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
 *
 * SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "config-kaichat.h"
#include "kaichatcommandlineparser.h"
#include "kaichatglobalconfig.h"
#include "kaichatmainwindow.h"
#include <KConfigGroup>
#include <KCrash>
#include <KLocalizedString>
#include <QApplication>
#include <QCommandLineParser>
#include <TextAutoGenerateText/TextAutoGenerateTextUtils>
#include <iostream>

#include <KAboutData>
#include <QIcon>

#include <KIconTheme>

#include <KStyleManager>

#if WITH_DBUS
#include <KDBusService>
#else
#include <KWindowSystem>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QWindow>
#include <kdsingleapplication.h>
#if !defined(Q_OS_WIN) && !defined(Q_OS_MACOS)
#include <private/qtx11extras_p.h>
#endif
#endif

// signal handler for SIGINT & SIGTERM
#ifdef Q_OS_UNIX
#include <KSignalHandler>
#include <signal.h>
#include <unistd.h>
#endif

using namespace Qt::Literals::StringLiterals;
int main(int argc, char *argv[])
{
    KIconTheme::initTheme();
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(u":/kaichat/kaichat.svg"_s));

    KStyleManager::initStyle();
#if !WITH_DBUS
    KDSingleApplication sapp;
#endif
    KLocalizedString::setApplicationDomain("kaichat"_ba);

    KAboutData aboutData(u"kaichat"_s,
                         i18n("KAIChat"),
                         QStringLiteral(KAICHAT_VERSION),
                         i18n("AI Chat"),
                         KAboutLicense::GPL_V2,
                         i18n("Copyright © 2025 Laurent Montel"));
    aboutData.addAuthor(i18nc("@info:credit", "Laurent Montel"), i18n("Maintainer"), u"montel@kde.org"_s);
    aboutData.setOrganizationDomain("kde.org"_ba);
    aboutData.setProductName("kaichat"_ba);
    aboutData.setProgramLogo(QIcon(u":/kaichat/kaichat.svg"_s));

    KAboutData::setApplicationData(aboutData);

    KCrash::initialize();
    QCommandLineParser parser;

    KAIChatCommandLineParser commandLineParser(&parser);

    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

    if (parser.isSet(commandLineParser.optionParserFromEnum(KAIChatCommandLineParser::OptionParser::ListInstances))) {
        KConfig config(TextAutoGenerateText::TextAutoGenerateTextUtils::instanceConfigFileName());
        const QStringList lst = TextAutoGenerateText::TextAutoGenerateTextUtils::instancesList(&config);
        std::cout << qPrintable(i18n("The following instances are available:")) << '\n';
        for (const QString &instanceName : lst) {
            const KConfigGroup grp = config.group(instanceName);
            const QString name = grp.readEntry("Name");
            std::cout << "   " << name.toLocal8Bit().data() << '\n';
        }
        return 0;
    }

    if (KAIChatGlobalConfig::self()->useCustomFont()) {
        qApp->setFont(KAIChatGlobalConfig::self()->generalFont());
    }

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
#if WITH_DBUS
    QObject::connect(&service, &KDBusService::activateRequested, mw, &KAIChatMainWindow::slotActivateRequested);
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

#ifdef Q_OS_UNIX
    /**
     * Set up signal handler for SIGINT and SIGTERM
     */
    KSignalHandler::self()->watchSignal(SIGINT);
    KSignalHandler::self()->watchSignal(SIGTERM);
    QObject::connect(KSignalHandler::self(), &KSignalHandler::signalReceived, &app, [](int signal) {
        if (signal == SIGINT || signal == SIGTERM) {
            printf("Shutting down...\n");
        }
    });
#endif

    mw->show();
    const int val = app.exec();
    return val;
}
