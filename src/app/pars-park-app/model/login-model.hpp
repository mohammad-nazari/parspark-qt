#ifndef ANAR_PARS_PARK_MODEL_LOGIN_HPP
#define ANAR_PARS_PARK_MODEL_LOGIN_HPP

#include "anar/model/database-model.hpp"
#include "database/user-model.hpp"

namespace anar::parspark::model {
   class LoginModel;
   using LoginModelPtr = std::shared_ptr<LoginModel>;
   class LoginModel
       : public UserModel
       , public anar::model::DataBaseModel {
     public:
      LoginModel()
          : anar::model::Model("Login", "Login") {
      }
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_LOGIN_HPP
