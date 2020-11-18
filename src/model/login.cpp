#include "login.hpp"

namespace anar::model {
   LoginPtr Login::Create() {
      return std::make_shared<Login>();
   }
   Login::Login()
       : BaseModel("Login") {
   }

   bool Login::FromJson(const json_nlohmann& json) {
      BaseModel::FromJson(json);
      m_user->FromJson(json["user"]);
      m_dataBase->FromJson(json["dataBase"]);
      return true;
   }
   json_nlohmann Login::ToJson() {
      json_nlohmann json = BaseModel::ToJson();
      json["user"] = m_user->ToJson();
      json["database"] = m_dataBase->ToJson();
      return json;
   }
}  // namespace anar::model
