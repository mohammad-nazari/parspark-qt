#ifndef ANAR_MODEL_ERROR_HPP
#define ANAR_MODEL_ERROR_HPP

#include <vector>

#include "anar/const/error-const.hpp"
#include "anar/model/model.hpp"

namespace anar::model {
   class ErrorModel : public anar::model::Model {
     public:
      ErrorModel()
          : anar::model::Model("Error", "Error") {
      }
      ~ErrorModel() override = default;

      uint64_t Code{0};
      ConstantModel Level{constant::ErrorLevel::ANAR_INFO};
      std::string Message;
      std::vector<ErrorModel> SubErrors{};
   };
}  // namespace anar::model
#endif  // ANAR_MODEL_ERROR_HPP
