#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "glog/logging.h"
#include "view/login/LoginView.hpp"
#include "view/settings/SettingsView.hpp"

int main(int argc, char* argv[]) {
    //    anar::test::NazariTest::RunTest();
    int appCode;
#ifdef _DEBUG
    FLAGS_logtostderr = true;
#endif
    FLAGS_log_dir = "logs";
    google::EnableLogCleaner(3);
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "Start application";

    QGuiApplication app(argc, argv);

    LOG(INFO) << "Show logging form";
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
        []() {
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.loadFromModule("ANAR.ParsPark.View", "Login");
    appCode = QGuiApplication::exec();

    // If login done successfully load main form
    // else exit from application
    if (anar::parspark::view::LoginView::Instance()->IsLoggedIn()) {
        LOG(INFO) << "Logged in successfully";
        LOG(INFO) << "Load application main window";
        QObject::connect(
            &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
            []() {
                QCoreApplication::exit(-1);
            },
            Qt::QueuedConnection);
        engine.loadFromModule("ANAR.ParsPark.View", "Main");
        appCode = QGuiApplication::exec();
    }
    LOG(INFO) << "Close application with code " << appCode;
    google::FlushLogFiles(google::LogSeverity());
    return appCode;
}
