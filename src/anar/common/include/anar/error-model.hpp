#ifndef ANAR_MODEL_ERROR_HPP
#define ANAR_MODEL_ERROR_HPP

#include <utility>
#include <vector>

#include "anar/error-const.hpp"
#include "anar/model.hpp"

namespace anar::model {
   class ErrorModel : public Model {
     public:
      ErrorModel(uint64_t code = 0, const ConstantModel& level = constant::ErrorLevel::ANAR_NO_ERROR, std::string message = "")
          : Model("Error", "Error")
          , Code(code)
          , Level(level)
          , Message(std::move(message)) {
      }
      ~ErrorModel() override = default;

      bool Accept(interfaces::IModelBindingVisitor& visitor) final {
         return visitor.Visit(*this);
      }

      uint64_t Code{0};
      ConstantModel Level{constant::ErrorLevel::ANAR_NO_ERROR};
      std::string Message;
      std::vector<ErrorModel> SubErrors{};
   };
   using ErrorModelPtr = std::shared_ptr<ErrorModel>;
}  // namespace anar::model
#endif  // ANAR_MODEL_ERROR_HPP
