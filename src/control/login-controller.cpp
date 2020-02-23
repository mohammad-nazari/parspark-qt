#include "login-controller.hpp"

#include <QSqlDatabase>
#include <QSqlQuery>

namespace parspark::control {
   LoginControllerPtr LoginController::Create() {
      return std::make_shared<LoginController>();
   }
   LoginController::LoginController(QObject* parent)
       : QObject(parent) {
   }

   bool LoginController::DoLogin(model::LoginPtr& login) {
      login->IsLoggedin(false);
      QSqlDatabase db;
      try {
         db = QSqlDatabase::database();
         db.setHostName(login->DataBase::Address());
         db.setDatabaseName(login->DataBase::DatabaseName());
         db.setUserName(login->DataBase::UserName());
         db.setPassword(login->DataBase::Password());
         if (db.open()) {
            QSqlQuery query;
            query.prepare(
                "select * from `parsparko`.`users` where`username`=:username "
                "and password=md5(:password)");
            query.bindValue(":username", login->User::UserName());
            query.bindValue(":password", login->User::Password());
            query.exec();
            login->IsLoggedin(query.size() > 0);
            if (!login->IsLoggedin()) {
               login->Error("User name or password is incorrect");
            }
            db.close();
         } else {
            login->Error("Incorrect database information");
         }
      } catch (std::exception& exception) {
         login->IsLoggedin(false);
         login->Error("DB Error: " + QString(exception.what()));
         db.close();
      }
      return login->IsLoggedin();
   }
} // namespace parspark::control
