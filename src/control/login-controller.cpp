#include "login-controller.hpp"

#include "service/s-settings.hpp"
#include <QSqlDatabase>
#include <QSqlQuery>

namespace parspark::control {
   LoginControllerPtr LoginController::Create() {
      return std::make_shared<LoginController>();
   }
   LoginController::LoginController()
       : BaseController() {
   }

   bool LoginController::DoLogin(const model::LoginPtr& login) {
      bool isLoggedIn{false};
      QSqlDatabase db;
      try {
         db = QSqlDatabase::database();
         db.setHostName(login->DataBase::Address());
         db.setDatabaseName(login->DataBase::DatabaseName());
         db.setUserName(login->DataBase::UserName());
         db.setPassword(login->DataBase::Password());
         db.setPort(login->DataBase::Port());
         if (db.open()) {
            QSqlQuery query;
            query.prepare(
                "select * from `parsparko`.`users` where`username`=:username "
                "and password=md5(:password)");
            query.bindValue(":username", login->User::UserName());
            query.bindValue(":password", login->User::Password());
            query.exec();
            isLoggedIn = query.size() > 0;
            if (!isLoggedIn) {
               m_error = "User name or password is incorrect";
            }
            db.close();
         } else {
            m_error = "Incorrect database information";
         }
      } catch (std::exception& exception) {
         isLoggedIn = false;
         m_error = "DB Error: " + QString(exception.what());
         db.close();
      }
      return isLoggedIn;
   }
   bool
   LoginController::SaveDataBaseSettings(const model::DataBasePtr& dataBase) {
      service::SSettings::Instance().DataBase(dataBase);
      auto isSaved = service::SSettings::Instance().Save();
      if (!isSaved) {
         m_error = service::SSettings::Instance().Error();
      }
      return isSaved;
   }
   model::DataBasePtr LoginController::LoadLoginSeeting() {
      return service::SSettings::Instance().DataBase();
   }
} // namespace parspark::control
