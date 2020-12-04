#include <QApplication>
#include <QDebug>
#include <QQmlComponent>

#include "Poco/Data/Session.h"
#include "Poco/Data/SessionFactory.h"
#include "const/view-const.hpp"
#include "view/common-view.hpp"
#include "view/login/login-view.hpp"
#include "view/settings/settings-view.hpp"

int main(int argc, char* argv[]) {
   //   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
   QGuiApplication app(argc, argv);
   // Register the singleton type provider with QML by calling this
   qmlRegisterType<anar::view::CommonView>(anar::constant::RegisterPackets::PARS_PARK_PACKAGE_NAME, anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION,
                                           anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION, "CommonApi");
   qmlRegisterType<anar::view::LoginView>(anar::constant::RegisterPackets::PARS_PARK_PACKAGE_NAME, anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION,
                                          anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION, "LoginApi");
   qmlRegisterType<anar::view::SettingsView>(anar::constant::RegisterPackets::PARS_PARK_PACKAGE_NAME, anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MAJOR_VERSION,
                                             anar::constant::RegisterPackets::PARS_PARK_PACKAGE_MINOR_VERSION, "SettingApi");

   // Register login form
   const QUrl loginUrl("qrc:/src/view/login/login.qml");
   QQmlEngine engine;
   QQmlComponent component(&engine, loginUrl);
   QObject* object = component.create();
   // Load Login form
   QGuiApplication::exec();

   auto* loginApi = object->findChild<QObject*>("loginApi");
   bool done{false};
   if (loginApi) {
      done = loginApi->property("done").toBool();
   }

   // If login done successfully load main form
   // else exit from application
   if (done) {
      // Register main form
      const QUrl mainUrl("qrc:/src/view/main/main.qml");
      QQmlComponent component1(&engine, mainUrl);
      object = component1.create();
      // Load main form
      QGuiApplication::exec();
   }
   delete object;
   return 1;
}
