#ifndef ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP
#define ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP

#include "anar/a-from-json-visitor.hpp"
#include "interface/i-pars-park-model-binding-visitor.hpp"

namespace anar::parspark::service {
   class FromJsonVisitor
       : public anar::service::AFromJsonVisitor
       , public interfaces::IParsParkModelBindingVisitor {
     public:
      FromJsonVisitor(json_nlohmann &jsonNlohmann);

      void Visit(model::UserModel *userModel) final;
      void Visit(model::LoginModel *loginModel) final;
   };
}  // namespace anar::parspark::service
#endif  // ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP
