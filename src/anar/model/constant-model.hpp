#ifndef ANAR_MODEL_CONSTANT_HPP
#define ANAR_MODEL_CONSTANT_HPP

#include "anar/model/model.hpp"

namespace anar::model {
   class ConstantModel : public anar::model::Model {
     public:
      ConstantModel(const uint32_t code, const std::string &name, const std::string &description)
          : anar::model::Model(name, description)
          , Code(code) {
      }
      uint32_t Code{0};
   };
}  // namespace anar::model

#endif  // ANAR_MODEL_CONSTANT_HPP
