#ifndef ANAR_CONST_ERROR_HPP
#define ANAR_CONST_ERROR_HPP

#include "constant-model.hpp"

namespace anar::constant {
    namespace ErrorLevel {
        const model::ConstantModel ANAR_NO_ERROR{0, "no-error", ""};
        const model::ConstantModel ANAR_LOW_INFO{1, "low-info", "Low information message"};
        const model::ConstantModel ANAR_INFO{2, "info", "Information message"};
        const model::ConstantModel ANAR_HIGH_INFO{3, "high-info", "High information message"};
        const model::ConstantModel ANAR_LOW_WARNING{10, "low-warning", "Low warning message"};
        const model::ConstantModel ANAR_WARNING{11, "warning", "Warning Message"};
        const model::ConstantModel ANAR_HIGH_WARNING{12, "high-warning", "High warning message"};
        const model::ConstantModel ANAR_LOW_ERROR{20, "low-error", "Low error Message"};
        const model::ConstantModel ANAR_ERROR{21, "error", "Error Message"};
        const model::ConstantModel ANAR_HIGH_ERROR{22, "high-error", "High error message"};
        const model::ConstantModel ANAR_LOW_CRITICAL{30, "low-critical", "Low critical message"};
        const model::ConstantModel ANAR_CRITICAL{31, "critical", "Critical Message"};
        const model::ConstantModel ANAR_HIGH_CRITICAL{32, "high-critical", "High critical message"};
        const model::ConstantModel ANAR_LOW_FATAL{40, "low-fatal", "Low fatal Message"};
        const model::ConstantModel ANAR_FATAL{41, "fatal", "Fatal Message"};
        const model::ConstantModel ANAR_HIGH_FATAL{42, "high-fatal", "High fatal message"};
    }  // namespace ErrorLevel
}  // namespace anar::constant
#endif  // ANAR_CONST_ERROR_HPP-
