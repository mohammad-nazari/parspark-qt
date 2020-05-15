#include "base-controller.hpp"

namespace parspark::control {
   BaseControllerPtr BaseController::Create() {
      return std::make_shared<BaseController>();
   }
   BaseController::BaseController() {
   }
} // namespace parspark::control
