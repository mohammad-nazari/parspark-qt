#ifndef ANAR_MODEL_CONSTANT_HPP
#define ANAR_MODEL_CONSTANT_HPP

#include "anar/model.hpp"

namespace anar::model {
   class ConstantModel : public Model {
     public:
      ConstantModel(const uint32_t code, const std::string &name, const std::string &description)
          : Model(name, description)
          , Code(code) {
      }
      ~ConstantModel() override = default;

      bool Accept(interfaces::IModelBindingVisitor &visitor) override {
         return visitor.Visit(*this);
      }

      uint32_t Code{0};
   };
}  // namespace anar::model

#endif  // ANAR_MODEL_CONSTANT_HPP
