#ifndef ANAR_BASE_SERVICE_HPP
#define ANAR_BASE_SERVICE_HPP

#include <QString>
#include <memory>

namespace anar::service {
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
}  // namespace anar::service

#endif  // ANAR_BASE_SERVICE_HPP
