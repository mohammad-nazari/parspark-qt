#include "database.hpp"

namespace anar::model {
   DataBasePtr DataBase::Create() {
      return std::make_shared<DataBase>();
   }
   DataBase::DataBase()
       : Model("DataBase", "Database") {
   }

   bool DataBase::FromJson(const json_nlohmann &json) {
      Model::FromJson(json);
      m_hostAddress = json["hostAddress"];
      m_userName = json["userName"];
      m_passWord = json["passWord"];
      m_port = json["port"];
      m_databaseName = json["databaseName"];
      return true;
   }
   json_nlohmann DataBase::ToJson() {
      json_nlohmann json = Model::ToJson();
      json["hostAddress"] = m_hostAddress;
      json["userName"] = m_userName;
      json["passWord"] = m_passWord;
      json["port"] = m_port;
      json["databaseName"] = m_databaseName;
      return json;
   }
}  // namespace anar::model
