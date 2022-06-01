#ifndef ANAR_PARS_PARK_SERVICE_ERROR_MANAGER_HPP
#define ANAR_PARS_PARK_SERVICE_ERROR_MANAGER_HPP

#include "anar/error-model.hpp"

namespace anar::common::service {
    class ErrorManager {
       public:
        static model::ErrorModel GenerateError(uint64_t code, const model::ConstantModel& level = constant::ErrorLevel::ANAR_NO_ERROR, std::string message = "");
        static model::ErrorModelPtr GenerateErrorPtr(uint64_t code, const model::ConstantModel& level = constant::ErrorLevel::ANAR_NO_ERROR, std::string message = "");
        static bool HaveNoError(const model::ErrorModel& error);
        static bool HaveNoError(const model::ErrorModelPtr& error);
        static bool HaveError(const model::ErrorModel& error);
        static bool HaveError(const model::ErrorModelPtr& error);
        static void ResetError(model::ErrorModel& error);
        static void ResetError(model::ErrorModelPtr error);
    };
}  // namespace anar::common::service

#endif  // ANAR_PARS_PARK_SERVICE_ERROR_MANAGER_HPP
