#ifndef SERVICE_BASE_SERVICE_HPP
#define SERVICE_BASE_SERVICE_HPP

#include <QString>
#include <memory>

namespace parspark::control {
   class BaseService;
   using BaseServicePtr = std::shared_ptr<BaseService>;
   class BaseService {
    public:
      static BaseServicePtr Create();
      explicit BaseService();

      QString Error() const {
         return m_error;
      }
      void Error(const QString& error) {
         m_error = error;
      }

    protected:
      QString m_error;
   };
} // namespace parspark::control

#endif // SERVICE_BASE_SERVICE_HPP
