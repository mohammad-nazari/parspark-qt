#ifndef ANAR_SERVICE_HPP
#define ANAR_SERVICE_HPP

#include "error-model.hpp"

namespace anar::common::service {
    class Service;
    using ServicePtr = std::shared_ptr<Service>;
    class Service {
       public:
        static ServicePtr Create();
        explicit Service();

        [[nodiscard]] model::ErrorModel Error() const {
            return m_error;
        }
        void Error(const model::ErrorModel& error) {
            //         m_error = error;
        }

       protected:
        model::ErrorModel m_error;
    };
}  // namespace anar::common::service

#endif  // ANAR_SERVICE_HPP
