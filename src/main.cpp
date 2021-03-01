#include <QApplication>
#include <QDebug>
#include <QQmlComponent>
#include <lib/googlelog/glog/logging.h>

#include "Poco/Data/Session.h"
#include "const/view-const.hpp"
#include "nazari-test.hpp"
#include "view/common-view.hpp"
#include "view/login/login-view.hpp"
#include "view/settings/settings-view.hpp"

int main(int argc, char* argv[]) {
   int appCode{-1};
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
   qmlRegisterType<anar::view::CommonView>(anar::constant::RegisterPackets::PARS_PARK_PACKAGE_NAME, anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION,
                                           anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION, "CommonApi");
   qmlRegisterType<anar::view::LoginView>(anar::constant::RegisterPackets::PARS_PARK_PACKAGE_NAME, anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION,
                                          anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION, "LoginApi");
   qmlRegisterType<anar::view::SettingsView>(anar::constant::RegisterPackets::PARS_PARK_PACKAGE_NAME, anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION,
                                             anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION, "SettingApi");
   LOG(INFO) << "Show logging form";
   // Register login form
   const QUrl loginUrl("qrc:/src/view/login/login.qml");
   QQmlEngine engine;
   QQmlComponent component(&engine, loginUrl);
   QObject* object = component.create();
   // Load Login form
   appCode = QGuiApplication::exec();

   auto* loginApi = object->findChild<QObject*>("loginApi");
   bool done{false};
   if (loginApi) {
      LOG(INFO) << "Logged in successfully";
      done = loginApi->property("done").toBool();
   }

   // If login done successfully load main form
   // else exit from application
   if (done) {
      LOG(INFO) << "Load application main window";
      // Register main form
      const QUrl mainUrl("qrc:/src/view/main/main.qml");
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
