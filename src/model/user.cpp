#include "user.hpp"

namespace parspark::model {
   User::User()
       : BaseModel("User") {
   }

   UserPtr User::Create() {
      return std::make_shared<User>();
   }

   bool User::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_userName = json["userName"].toString();
      m_password = json["password"].toString();
      m_firstName = json["firstName"].toString();
      m_lastName = json["lastName"].toString();
      m_address = json["address"].toString();
      m_phoneNumber = json["phoneNumber"].toString();
      m_userType = json["userType"].toString();
      m_registerTime = json["registerTime"].toULongLong();
      return true;
   }

   const QVariantMap User::ToJson() const {
      QVariantMap json;
      json["userName"] = m_userName;
      json["password"] = m_password;
      json["firstName"] = m_firstName;
      json["lastName"] = m_lastName;
      json["address"] = m_address;
      json["phoneNumber"] = m_phoneNumber;
      json["userType"] = m_userType;
      json["registerTime"] = m_registerTime;
      return json;
   }
} // namespace parspark::model
