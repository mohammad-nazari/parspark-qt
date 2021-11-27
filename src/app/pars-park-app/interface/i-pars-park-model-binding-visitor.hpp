#ifndef ANAR_PARS_PARK_INTERFACE_MODEL_BINDING_VISITOR_HPP
#define ANAR_PARS_PARK_INTERFACE_MODEL_BINDING_VISITOR_HPP

#include "anar/i-visitor.hpp"

namespace anar::parspark::model {
   class LoginModel;
   class UserModel;
}  // namespace anar::parspark::model

namespace anar::parspark::interfaces {
   class IParsParkModelBindingVisitor : virtual public anar::interfaces::IVisitor {
     public:
      virtual void Visit(model::LoginModel *loginModel) = 0;
      virtual void Visit(model::UserModel *userModel) = 0;
   };
}  // namespace anar::parspark::interfaces
#endif  // ANAR_PARS_PARK_INTERFACE_MODEL_BINDING_VISITOR_HPP
