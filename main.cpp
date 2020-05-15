#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlProperty>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <service/s-settings.hpp>
#include <view/login/login-view.hpp>
#include <view/settings/settings-view.hpp>

int main(int argc, char* argv[]) {

   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QGuiApplication app(argc, argv);
   //    app.setWindowIcon(QIcon(":/src/pictures/Icon1.png"));

   // Set database to mysql
   QSqlDatabase::addDatabase("QMYSQL");

   // Third, register the singleton type provider with QML by calling this
   qmlRegisterType<parspark::view::LoginView>("ParsPark.View", 1, 0,
                                              "LoginApi");
   qmlRegisterType<parspark::view::SettingsView>("ParsPark.View", 1, 0,
                                                 "SettingApi");

   // Register login form
   const QUrl loginUrl(QStringLiteral("qrc:/src/view/login/login.qml"));
   QQmlEngine engine;
   QQmlComponent component(&engine, loginUrl);
   QObject* object = component.create();

   // Load Login form
   app.exec();

   QObject* loginApi = object->findChild<QObject*>("loginApi");
   bool done{false};
   if (loginApi)
      done = loginApi->property("done").toBool();

   // If login done succcessfully load main form
   // else exit from application
   if (done) {
      // Register main form
      const QUrl mainUrl(QStringLiteral("qrc:/src/view/main/main.qml"));
      QQmlComponent component(&engine, mainUrl);
      object = component.create();
      // Load main form
      app.exec();
   }
   delete object;
   return 1;
}
