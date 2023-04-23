#ifndef ANAR_PARS_PARK_MODEL_LOGIN_HPP
#define ANAR_PARS_PARK_MODEL_LOGIN_HPP

#include "anar/database-model.hpp"
#include "database/user-model.hpp"
#include "interface/i-pars-park-model-binding-visitor.hpp"

namespace anar::parspark::model {
   class LoginModel;
   using LoginModelPtr = std::shared_ptr<LoginModel>;
   class LoginModel
       : public anar::common::model::DataBaseModel
       , public UserModel {
     public:
      LoginModel()
          : ParsParkModel("Login", "Login") {
      }
      ~LoginModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_LOGIN_HPP
