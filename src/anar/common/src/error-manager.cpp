#include "anar/error-manager.hpp"

namespace anar::service {
    model::ErrorModel ErrorManager::GenerateError(uint64_t code, const model::ConstantModel& level, std::string message) {
        return model::ErrorModel(code, level, level.Description + ": " + message);
    }
    model::ErrorModelPtr ErrorManager::GenerateErrorPtr(uint64_t code, const model::ConstantModel& level, std::string message) {
        return std::make_shared<model::ErrorModel>(code, level, level.Description + ": " + message);
    }
    bool ErrorManager::HaveNoError(const model::ErrorModel& error) {
        return error.Code <= 0;
    }
    bool ErrorManager::HaveNoError(const model::ErrorModelPtr& error) {
        return error->Code <= 0;
    }
    bool ErrorManager::HaveError(const model::ErrorModel& error) {
        return error.Code > 0;
    }
    bool ErrorManager::HaveError(const model::ErrorModelPtr& error) {
        return error->Code > 0;
    }
    void ErrorManager::ResetError(model::ErrorModel& error) {
        error.Code = 0;
        error.Level = constant::ErrorLevel::ANAR_NO_ERROR;
        error.Message.clear();
        error.SubErrors.clear();
    }
    void ErrorManager::ResetError(model::ErrorModelPtr error) {
        error->Code = 0;
        error->Level = constant::ErrorLevel::ANAR_NO_ERROR;
        error->Message.clear();
        error->SubErrors.clear();
    }
}  // namespace anar::service