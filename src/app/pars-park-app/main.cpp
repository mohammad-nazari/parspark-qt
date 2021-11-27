#include <QApplication>
#include <QDebug>
#include <QQmlComponent>

#include "anar/json-parser.hpp"
#include "const/view-const.hpp"
#include "glog/logging.h"
#include "nazari-test.hpp"
#include "view/common-view.hpp"
#include "view/login/login-view.hpp"
#include "view/settings/settings-view.hpp"

using namespace anar::parspark;

int main(int argc, char* argv[]) {
         anar::test::NazariTest::RunTest();
         return 0;
   int appCode;
   //   FLAGS_logtostderr = true;
   FLAGS_log_dir = "logs";
   google::EnableLogCleaner(3);
   google::InitGoogleLogging(argv[0]);
   LOG(INFO) << "Start application";
   //   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QGuiApplication app(argc, argv);
   LOG(INFO) << "Register single classes in qml";
   // Register the singleton type provider with QML by calling this
   qmlRegisterSingletonType<view::CommonView>(constant::RegisterPackets::ANAR_COMMON_PACKAGE_NAME.Description.c_str(), constant::RegisterPackets::ANAR_PACKAGE_MAJOR_VERSION.Code,
                                              constant::RegisterPackets::ANAR_PACKAGE_MINOR_VERSION.Code, constant::RegisterPackets::ANAR_COMMON_PACKAGE_NAME.Name.c_str(),
                                              view::CommonView::QmlInstance);
   qmlRegisterSingletonType<view::LoginView>(constant::RegisterPackets::ANAR_LOGIN_PACKAGE_NAME.Description.c_str(), constant::RegisterPackets::ANAR_PACKAGE_MAJOR_VERSION.Code,
                                             constant::RegisterPackets::ANAR_PACKAGE_MINOR_VERSION.Code, constant::RegisterPackets::ANAR_LOGIN_PACKAGE_NAME.Name.c_str(), view::LoginView::QmlInstance);
   qmlRegisterSingletonType<view::SettingsView>(constant::RegisterPackets::ANAR_SETTINGS_PACKAGE_NAME.Description.c_str(), constant::RegisterPackets::ANAR_PACKAGE_MAJOR_VERSION.Code,
                                                constant::RegisterPackets::ANAR_PACKAGE_MINOR_VERSION.Code, constant::RegisterPackets::ANAR_SETTINGS_PACKAGE_NAME.Name.c_str(),
                                                view::SettingsView::QmlInstance);
   LOG(INFO) << "Show logging form";
   // Register login form
   const QUrl loginUrl("qrc:/src/app/pars-park-app/view/login/login.qml");
   QQmlEngine engine;
   QQmlComponent component(&engine, loginUrl);
   QObject* object = component.create();
   // Load Login form
   appCode = QGuiApplication::exec();

   // If login done successfully load main form
   // else exit from application
   if (view::LoginView::Instance()->IsLoggedIn()) {
      LOG(INFO) << "Logged in successfully";
      LOG(INFO) << "Load application main window";
      // Register main form
      const QUrl mainUrl("qrc:/src/app/pars-park-app/view/main/main.qml");
      QQmlComponent component1(&engine, mainUrl);
      object = component1.create();
      // Load main form
      appCode = QGuiApplication::exec();
   }
   delete object;
   LOG(INFO) << "Close application with code " << appCode;
   google::FlushLogFiles(google::LogSeverity());
   return appCode;
   return 0;
}
