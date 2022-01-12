#ifndef ANAR_CONTROLLER_HPP
#define ANAR_CONTROLLER_HPP

#include <memory>
#include <string>

#include "error-model.hpp"

namespace anar::controller {
    class Controller;
    using ControllerPtr = std::shared_ptr<Controller>;
    class Controller {
       public:
        static ControllerPtr Create();
        explicit Controller();
        virtual ~Controller() = default;

        [[nodiscard]] const model::ErrorModel& Error() const {
            return m_error;
        }
        void Error(const model::ErrorModel& error) {
            m_error = error;
        }

       protected:
        model::ErrorModel m_error;
    };
}  // namespace anar::controller
#endif  // ANAR_CONTROLLER_HPP
