#ifndef ANAR_PARS_PARK_MODEL_LOGIN_HPP
#define ANAR_PARS_PARK_MODEL_LOGIN_HPP

#include "anar/database-model.hpp"
#include "database/user-model.hpp"
#include "interface/i-pars-park-model-binding-visitor.hpp"

namespace anar::parspark::model {
   class LoginModel;
   using LoginModelPtr = std::shared_ptr<LoginModel>;
   class LoginModel
       : public anar::model::Model
       , public anar::model::DataBaseModel
       , public UserModel {
     public:
      LoginModel()
          : anar::model::Model("Login", "Login") {
      }

      void Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         modelBindingVisitor->Visit(this);
      }
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_LOGIN_HPP
