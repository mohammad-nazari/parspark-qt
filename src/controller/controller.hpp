#ifndef ANAR_BASE_CONTROLLER_HPP
#define ANAR_BASE_CONTROLLER_HPP

#include <memory>
#include <string>

namespace anar::controller {
   class Controller;
   using ControllerPtr = std::shared_ptr<Controller>;
   class Controller {
     public:
      static ControllerPtr Create();
      explicit Controller();
      virtual ~Controller() = default;

      [[nodiscard]] const std::string &Error() const {
         return m_error;
      }
      void Error(const std::string &error) {
         m_error = error;
      }

     protected:
      std::string m_error;
   };
}  // namespace anar::controller
#endif  // ANAR_BASE_CONTROLLER_HPP
