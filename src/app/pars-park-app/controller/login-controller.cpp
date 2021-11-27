#include "login-controller.hpp"

#include <Poco/DigestStream.h>
#include <Poco/MD5Engine.h>

#include <iostream>

#include "anar/string.hpp"
#include "anar/mysql-database.hpp"
#include "service/model-binding/database/mysql/person-model-odb.hxx"
#include "service/s-settings.hpp"

namespace anar::parspark::controller {
   LoginControllerPtr LoginController::Create() {
      return std::make_shared<LoginController>();
   }
   LoginController::LoginController()
       : Controller() {
   }

   bool LoginController::DoLogin(const model::LoginModel& login) {
      bool isLoggedIn{false};
//      std::string passWord = common::String::MD5(login->PassWord());
//      database::MysqlDataBase db(login->DataBase());
      try {
//         if (db.Connect()) {
//            odb::query<users> query(odb::query<users>::username == login->UserName() && odb::query<users>::password == passWord);
//            std::vector<users> userList = db.Select<users>(query);
//            isLoggedIn = !userList.empty();
//            if (!isLoggedIn) {
//               m_error = "User name '" + login->UserName() + "' or password '" + login->PassWord() + "(" + passWord + ")' is incorrect";
//            }
//         } else {
//            m_error = "Incorrect database information";
//         }
      } catch (std::exception& exception) {
         isLoggedIn = false;
//         m_error = "DB Error: " + std::string(exception.what());
      }
      return isLoggedIn;
   }
   bool LoginController::SaveDataBaseSettings(const anar::model::DataBaseModel& dataBase) {
      service::SSettings::Instance()->DataBase(dataBase);
      auto isSaved = service::SSettings::Instance()->Save();
      if (!isSaved) {
//         m_error = service::SSettings::Instance()->Error();
      }
      return isSaved;
   }
   anar::model::DataBaseModel LoginController::LoadLoginSetting() {
      return service::SSettings::Instance()->DataBase();
   }
}  // namespace anar::controller
