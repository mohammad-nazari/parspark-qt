#include "login-controller.hpp"

#include <Poco/MD5Engine.h>

#include <iostream>
#include <odb/query.hxx>

#include "anar/database-const.hpp"
#include "anar/database-factory.hpp"
#include "anar/error-manager.hpp"
#include "anar/mysql-database.hpp"
#include "anar/string.hpp"
#include "model/database/user-model.hpp"
#include "service/model-binding/database/mysql/user-model-odb.hxx"
#include "service/s-settings.hpp"

namespace anar::parspark::controller {
    LoginControllerPtr LoginController::Create() {
        return std::make_shared<LoginController>();
    }

    LoginController::LoginController()
        : Controller() {
    }

    bool LoginController::DoLogin(const model::LoginModel &login) {
        try {
            anar::common::service::ErrorManager::ResetError(m_error);
            std::string passWord = anar::common::service::String::SHA512(login.PassWord);
            anar::common::database::DatabasePtr db = anar::common::database::DatabaseFactory::Create(anar::common::constant::DatabaseEngines::ANAR_MYSQL.Name, login);
            if (!db) {
                m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR, "Incorrect database information");
                return anar::common::service::ErrorManager::HaveNoError(m_error);
            }
            if (!db->Connect()) {
                m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR, "Incorrect database information");
                return anar::common::service::ErrorManager::HaveNoError(m_error);
            }
            odb::query<model::UserModel> query(odb::query<model::UserModel>::UserName == login.UserName && odb::query<model::UserModel>::PassWord == passWord);
            //                    odb::query<model::UserModel> query(odb::query<model::UserModel>::Id == 1);
            std::vector<model::UserModel> userList;
            if (!db->Select<model::UserModel>(query, userList)) {
                m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR, "Database Error");
                m_error.SubErrors.emplace_back(db->Error());
                return anar::common::service::ErrorManager::HaveNoError(m_error);
            }
            if (userList.empty()) {
                m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR,
                                                                             "User name '" + login.UserName + "' or password '" + login.PassWord + "(" + passWord + ")' is incorrect.");
            }
            /*odb::query<model::ContactModel> query(odb::query<model::ContactModel>::Id == 1);
            std::vector<model::ContactModel> contactList;
            if (db->Select<model::ContactModel>(query, contactList)) {
                if (contactList.empty()) {
                                      m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR,
                                                                                             "User name '" + login.UserName + "' or password '" + login.PassWord + "(" + passWord + ")' is
                                                                                             incorrect.");
                }
            } else {
                m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR, "Database Error");
                m_error.SubErrors.emplace_back(db->Error());
            }*/
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateError(1, anar::common::constant::ErrorLevel::ANAR_HIGH_ERROR, "DB Error: " + std::string(exception.what()));
        }
        return anar::common::service::ErrorManager::HaveNoError(m_error);
    }

    bool LoginController::SaveDataBaseSettings(const anar::common::model::DataBaseModel &dataBase) {
        anar::common::service::ErrorManager::ResetError(m_error);
        service::SSettings::Instance()->DataBase(dataBase);
        if (!service::SSettings::Instance()->Save()) {
            m_error = service::SSettings::Instance()->Error();
        }
        return anar::common::service::ErrorManager::HaveNoError(m_error);
    }

    anar::common::model::DataBaseModel LoginController::LoadLoginSetting() {
        return service::SSettings::Instance()->DataBase();
    }
}  // namespace anar::parspark::controller
