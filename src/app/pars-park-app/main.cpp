#include <QApplication>
#include <QDebug>
#include <QQmlComponent>

#include "anar/service/model-binding/json/json-parser.hpp"
#include "const/view-const.hpp"
#include "glog/logging.h"
#include "nazari-test.hpp"
#include "view/common-view.hpp"
#include "view/login/login-view.hpp"
#include "view/settings/settings-view.hpp"

int main(int argc, char* argv[]) {
   //   anar::test::NazariTest::RunTest();
   //   return 0;
   int appCode;
   //   FLAGS_logtostderr = true;
   FLAGS_log_dir = "logs";
   google::EnableLogCleaner(3);
   google::InitGoogleLogging(argv[0]);
   LOG(INFO) << "Start application";
   //   anar::NazariTest::TestPocoMySQL();
   //   return 0;
   //   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QGuiApplication app(argc, argv);
   LOG(INFO) << "Register single classes in qml";
   // Register the singleton type provider with QML by calling this
   qmlRegisterSingletonType<anar::parspark::view::CommonView>(anar::parspark::constant::RegisterPackets::PARS_PARK_COMMON_PACKAGE_NAME.Description.c_str(),
                                                              anar::parspark::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION.Code,
                                                              anar::parspark::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION.Code,
                                                              anar::parspark::constant::RegisterPackets::PARS_PARK_COMMON_PACKAGE_NAME.Name.c_str(), anar::parspark::view::CommonView::QmlInstance);
   qmlRegisterSingletonType<anar::parspark::view::LoginView>(anar::parspark::constant::RegisterPackets::PARS_PARK_LOGIN_PACKAGE_NAME.Description.c_str(),
                                                             anar::parspark::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION.Code,
                                                             anar::parspark::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION.Code,
                                                             anar::parspark::constant::RegisterPackets::PARS_PARK_LOGIN_PACKAGE_NAME.Name.c_str(), anar::parspark::view::LoginView::QmlInstance);
   qmlRegisterSingletonType<anar::parspark::view::SettingsView>(
       anar::parspark::constant::RegisterPackets::PARS_PARK_SETTINGS_PACKAGE_NAME.Description.c_str(), anar::parspark::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION.Code,
       anar::parspark::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION.Code, anar::parspark::constant::RegisterPackets::PARS_PARK_SETTINGS_PACKAGE_NAME.Name.c_str(),
       anar::parspark::view::SettingsView::QmlInstance);
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
   if (anar::parspark::view::LoginView::QmlInstance(nullptr, nullptr)->IsLoggedIn()) {
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
}
