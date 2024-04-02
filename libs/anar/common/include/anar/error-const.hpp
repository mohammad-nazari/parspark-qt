#ifndef ANAR_CONST_ERROR_HPP
#define ANAR_CONST_ERROR_HPP

#include "constant-model.hpp"

namespace anar::common::constant {
    namespace ErrorLevel {
        const model::ConstantModel ANAR_NO_ERROR{"no-error", "", 0};
        const model::ConstantModel ANAR_LOW_INFO{"low-info", "Low information message", 1};
        const model::ConstantModel ANAR_INFO{"info", "Information message", 2};
        const model::ConstantModel ANAR_HIGH_INFO{"high-info", "High information message", 3};
        const model::ConstantModel ANAR_LOW_WARNING{"low-warning", "Low warning message", 10};
        const model::ConstantModel ANAR_WARNING{"warning", "Warning Message", 11};
        const model::ConstantModel ANAR_HIGH_WARNING{"high-warning", "High warning message", 12};
        const model::ConstantModel ANAR_LOW_ERROR{"low-error", "Low error Message", 20};
        const model::ConstantModel ANAR_ERROR{"error", "Error Message", 21};
        const model::ConstantModel ANAR_HIGH_ERROR{"high-error", "High error message", 22};
        const model::ConstantModel ANAR_LOW_CRITICAL{"low-critical", "Low critical message", 30};
        const model::ConstantModel ANAR_CRITICAL{"critical", "Critical Message", 31};
        const model::ConstantModel ANAR_HIGH_CRITICAL{"high-critical", "High critical message", 32};
        const model::ConstantModel ANAR_LOW_FATAL{"low-fatal", "Low fatal Message", 40};
        const model::ConstantModel ANAR_FATAL{"fatal", "Fatal Message", 41};
        const model::ConstantModel ANAR_HIGH_FATAL{"high-fatal", "High fatal message", 42};
    }  // namespace ErrorLevel
}  // namespace anar::common::constant
#endif  // ANAR_CONST_ERROR_HPP-
