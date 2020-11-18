#include "base-controller.hpp"

namespace anar::controller {
   BaseControllerPtr BaseController::Create() {
      return std::make_shared<BaseController>();
   }
   BaseController::BaseController() = default;
}  // namespace anar::controller
