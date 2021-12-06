#ifndef ANAR_ABSTRACT_FROM_JSON_VISITOR_HPP
#define ANAR_ABSTRACT_FROM_JSON_VISITOR_HPP

#include "a-jsonable.hpp"
#include "i-model-binding-visitor.hpp"

namespace anar::service {
   class AFromJsonVisitor : virtual public interfaces::IModelBindingVisitor {
     public:
      AFromJsonVisitor(json_nlohmann &jsonNlohmann);

      bool Visit(model::Model *model) final;
      bool visit(model::ConstantModel *constant) final;
      bool visit(model::ErrorModel *error) final;
      bool Visit(model::DataBaseModel *dataBase) final;

     protected:
      json_nlohmann &m_json;
   };
}  // namespace anar::service
#endif  // ANAR_ABSTRACT_FROM_JSON_VISITOR_HPP
