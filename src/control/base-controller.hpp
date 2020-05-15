#ifndef CONTROL_BASE_CONTROLLER_HPP
#define CONTROL_BASE_CONTROLLER_HPP

#include <QString>
#include <memory>

namespace parspark::control {
   class BaseController;
   using BaseControllerPtr = std::shared_ptr<BaseController>;
   class BaseController {
    public:
      static BaseControllerPtr Create();
      explicit BaseController();

      QString Error() const
      {
          return m_error;
      }
      void Error(const QString &error)
      {
          m_error = error;
      }

   protected:
      QString m_error;
   };
} // namespace parspark::control
#endif // CONTROL_BASE_CONTROLLER_HPP
