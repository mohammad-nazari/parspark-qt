#include "base-service.hpp"

namespace parspark::control {
   BaseServicePtr BaseService::Create() {
      return std::make_shared<BaseService>();
   }
   BaseService::BaseService() {
   }
} // namespace parspark::control
