#include "login-controller.hpp"

#include <iostream>

#include "common/string.hpp"
#include "database/mysql/mysql-database.hpp"
#include "lib/poco/Foundation/include/Poco/DigestStream.h"
#include "lib/poco/Foundation/include/Poco/MD5Engine.h"
#include "model/database/person-odb.hxx"
#include "service/s-settings.hpp"

namespace anar::controller {
   LoginControllerPtr LoginController::Create() {
      return std::make_shared<LoginController>();
   }
   LoginController::LoginController()
       : BaseController() {
   }

   bool LoginController::DoLogin(const model::LoginPtr& login) {
      bool isLoggedIn{false};
      std::string passWord = common::String::MD5(login->PassWord());
      database::MysqlDataBase db(login->DataBase());
      try {
         if (db.Connect()) {
            odb::query<users> query(odb::query<users>::username == login->UserName() && odb::query<users>::password == passWord);
            std::vector<users> userList = db.Select<users>(query);
            isLoggedIn = !userList.empty();
            if (!isLoggedIn) {
               m_error = "User name '" + login->UserName() + "' or password '" + login->PassWord() + "(" + passWord + ")' is incorrect";
            }
         } else {
            m_error = "Incorrect database information";
         }
      } catch (std::exception& exception) {
         isLoggedIn = false;
         m_error = "DB Error: " + std::string(exception.what());
      }
      return isLoggedIn;
   }
   bool LoginController::SaveDataBaseSettings(const model::DataBasePtr& dataBase) {
      service::SSettings::Instance()->DataBase(dataBase);
      auto isSaved = service::SSettings::Instance()->Save();
      if (!isSaved) {
         m_error = service::SSettings::Instance()->Error();
      }
      return isSaved;
   }
   model::DataBasePtr LoginController::LoadLoginSetting() {
      return service::SSettings::Instance()->DataBase();
   }
}  // namespace anar::controller