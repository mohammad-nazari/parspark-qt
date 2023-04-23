#include "anar/controller.hpp"

namespace anar::common::controller {
    ControllerPtr Controller::Create() {
        return std::make_shared<Controller>();
    }
    Controller::Controller() = default;
}  // namespace anar::common::controller
