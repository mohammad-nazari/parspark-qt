#include "anar/service.hpp"

namespace anar::service {
   ServicePtr Service::Create() {
      return std::make_shared<Service>();
   }
   Service::Service() = default;
}  // namespace anar::service
