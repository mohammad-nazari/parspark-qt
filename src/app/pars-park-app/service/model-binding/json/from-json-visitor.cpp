#include "from-json-visitor.hpp"

#include <iostream>

#include "model/database/user-model.hpp"

namespace anar::parspark::service {
   FromJsonVisitor::FromJsonVisitor(json_nlohmann &jsonNlohmann)
       : anar::service::AFromJsonVisitor(jsonNlohmann) {
   }

   void FromJsonVisitor::Visit(model::UserModel *userModel) {
      //      userModel->Model::Accept(this);
      userModel->UserName = m_json["UserName"];
      userModel->PassWord = m_json["PassWord"];
      //      userModel->Person = m_json["Person"];
      userModel->Type = m_json["Type"];
      //      userModel->CreatingUser = m_json["CreatingUser"];
      //      userModel->UpdatingUser = m_json["UpdatingUser"];
      userModel->CreatedTime = m_json["CreatedTime"];
      if (!m_json["CreatedTime"].is_null()) {
         userModel->UpdatedTime = std::make_shared<time_t>(m_json["CreatedTime"]);
      }
      std::cout << "User model is visited!" << std::endl;
   }
   void FromJsonVisitor::Visit(model::LoginModel *loginModel) {
      std::cout << "Login model is visited!" << std::endl;
   }
}  // namespace anar::parspark::service
