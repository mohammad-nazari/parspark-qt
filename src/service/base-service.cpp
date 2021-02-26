#include "base-service.hpp"

namespace anar::service {
   BaseServicePtr BaseService::Create() {
      return std::make_shared<BaseService>();
   }
   BaseService::BaseService() = default;
}  // namespace anar::service
