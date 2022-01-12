#ifndef ANAR_ABSTRACT_TO_JSON_VISITOR_HPP
#define ANAR_ABSTRACT_TO_JSON_VISITOR_HPP

#include "a-jsonable.hpp"
#include "i-model-binding-visitor.hpp"

namespace anar::service {
   class AToJsonVisitor : virtual public interfaces::IModelBindingVisitor {
     public:
      AToJsonVisitor(nlohmann::ordered_json &jsonNlohmann);

      bool Visit(model::Model &model) final;
      bool visit(model::ConstantModel &constant) final;
      bool visit(model::ErrorModel &error) final;
      bool Visit(model::DataBaseModel &dataBase) final;

     protected:
      nlohmann::ordered_json &m_json;
   };
}  // namespace anar::service

#endif  // ANAR_ABSTRACT_TO_JSON_VISITOR_HPP
