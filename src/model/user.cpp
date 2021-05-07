#include "user.hpp"

namespace anar::model {
   UserPtr User::Create() {
      return std::make_shared<User>();
   }
   User::User()
       : Model("User", "User") {
   }

   bool User::FromJson(const json_nlohmann &json) {
      Model::FromJson(json);
      m_userName = json["userName"];
      m_passWord = json["passWord"];
      m_firstName = json["firstName"];
      m_lastName = json["lastName"];
      m_address = json["address"];
      m_phoneNumber = json["phoneNumber"];
      m_userType = json["userType"];
      m_registerTime = json["registerTime"];
      return true;
   }
   json_nlohmann User::ToJson() {
      json_nlohmann json = Model::ToJson();
      json["userName"] = m_userName;
      json["passWord"] = m_passWord;
      json["firstName"] = m_firstName;
      json["lastName"] = m_lastName;
      json["address"] = m_address;
      json["phoneNumber"] = m_phoneNumber;
      json["userType"] = m_userType;
      json["registerTime"] = m_registerTime;
      return json;
   }
}  // namespace anar::model
