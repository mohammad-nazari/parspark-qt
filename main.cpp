#include <QGuiApplication>
#include <QIcon>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <control/settings-controller.hpp>
#include <view/login/login-view.hpp>
#include <view/settings/settings-view.hpp>

int main(int argc, char* argv[]) {
   qDebug() << argv[0] << endl;
   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

   QGuiApplication app(argc, argv);
   //    app.setWindowIcon(QIcon(":/src/pictures/Icon1.png"));
   /**
    * @brief engine
    */

   // Set database to mysql
   QSqlDatabase::addDatabase("QMYSQL");

   // Load settings from json file
   parspark::control::SSettingsController::Instance()->Load();

   QQmlApplicationEngine engine;
   auto root_context = engine.rootContext();

   parspark::view::LoginView loginView;
   loginView.loadLoginInfo();
   parspark::view::SettingsView settingsView;
   // Add view classes to context to reach data in QML
   root_context->setContextProperty("login", &loginView);
   root_context->setContextProperty("settings", &settingsView);

   // Load Login form
   const QUrl url(QStringLiteral("qrc:/src/view/login/login.qml"));
   QObject::connect(
       &engine, &QQmlApplicationEngine::objectCreated, &app,
       [url](QObject* obj, const QUrl& objUrl) {
          if (!obj && url == objUrl)
             QCoreApplication::exit(-1);
       },
       Qt::QueuedConnection);
   engine.load(url);
   app.exec();
   // If login done succcessfully load main form
   // else exit from application
   if (loginView.IsLoggedin()) {
      const QUrl url2(QStringLiteral("qrc:/src/view/main/main.qml"));
      QObject::connect(
          &engine, &QQmlApplicationEngine::objectCreated, &app,
          [url2](QObject* obj2, const QUrl& objUrl2) {
             if (!obj2 && url2 == objUrl2)
                QCoreApplication::exit(-1);
          },
          Qt::QueuedConnection);
      engine.load(url2);

      app.exec();
   }
   return 1;
}
