#ifndef ANAR_LOGIN_HPP
#define ANAR_LOGIN_HPP

#include "anar/model/database-model.hpp"
#include "user-model.hpp"

namespace anar::model {
   class Login;
   using LoginPtr = std::shared_ptr<Login>;
   class Login
       : public UserModel
       , public DataBaseModel {
     public:
      Login()
          : Model("Login") {
      }
      ~Login() override = default;
   };
}  // namespace anar::model
#endif  // ANAR_LOGIN_HPP
