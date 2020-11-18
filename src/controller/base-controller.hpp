#ifndef ANAR_BASE_CONTROLLER_HPP
#define ANAR_BASE_CONTROLLER_HPP

#include <memory>
#include <string>

namespace anar::controller {
   class BaseController;
   using BaseControllerPtr = std::shared_ptr<BaseController>;
   class BaseController {
     public:
      static BaseControllerPtr Create();
      explicit BaseController();
      virtual ~BaseController() = default;

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
