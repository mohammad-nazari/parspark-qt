#include "anar/service.hpp"

namespace anar::common::service {
    ServicePtr Service::Create() {
        return std::make_shared<Service>();
    }
    Service::Service() = default;
}  // namespace anar::common::service
