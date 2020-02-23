#include "database.hpp"

namespace parspark::model {
   DataBasePtr DataBase::Create() {
      return std::make_shared<DataBase>();
   }
   DataBase::DataBase()
       : BaseModel("DataBase") {
   }

   bool DataBase::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_address = json["address"].toString();
      m_userName = json["userName"].toString();
      m_password = json["password"].toString();
      m_port = json["port"].toUInt();
      m_databaseName = json["databaseName"].toString();
      return true;
   }
   const QVariantMap DataBase::ToJson() const {
      QVariantMap json;
      json["address"] = m_address;
      json["userName"] = m_userName;
      json["password"] = m_password;
      json["port"] = m_port;
      json["databaseName"] = m_databaseName;
      return json;
   }
} // namespace parspark::model
