#include "s-settings.hpp"

#include <fstream>
#include <memory>

#include "anar/error-manager.hpp"
#include "service/model-binding/json/from-json-visitor.hpp"
#include "service/model-binding/json/to-json-visitor.hpp"

namespace anar::parspark::service {
    SSettingsPtr SSettings::_instance = nullptr;

    SSettings::SSettings() = default;
    SSettingsPtr SSettings::Instance() {
        if (_instance == nullptr) {
            _instance.reset(new SSettings);
            _instance->Load();
        }
        return _instance;
    }
    void SSettings::Destroy() {
        if (_instance != nullptr) {
            _instance = nullptr;
        }
    }

    bool SSettings::Load(const std::string& address) {
        try {
            ::anar::service::ErrorManager::ResetError(m_error);
            std::ifstream file(address, std::ios::in);
            if (file.is_open()) {
                std::string data = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                nlohmann::ordered_json json = nlohmann::json::parse(data);
                FromJsonVisitor fromJsonVisitor(json);
                if (!m_settings.Accept(fromJsonVisitor)) {
                    m_error = ::anar::service::ErrorManager::GenerateError(1, anar::constant::ErrorLevel::ANAR_HIGH_ERROR, "Error on read settings file");
                    m_error.SubErrors.emplace_back(*fromJsonVisitor.Error());
                }
            } else {
                m_error = ::anar::service::ErrorManager::GenerateError(1, anar::constant::ErrorLevel::ANAR_HIGH_ERROR, "Error on open settings file");
            }
        } catch (std::exception& exception) {
            m_error = ::anar::service::ErrorManager::GenerateError(1, anar::constant::ErrorLevel::ANAR_HIGH_ERROR, "Error on read settings file");
        }
        return ::anar::service::ErrorManager::HaveNoError(m_error);
    }
    bool SSettings::Save(const std::string& address) {
        try {
            ::anar::service::ErrorManager::ResetError(m_error);
            std::ofstream file(address, std::ios::out);
            if (file.is_open()) {
                nlohmann::ordered_json json;
                ToJsonVisitor toJsonVisitor(json);
                if (m_settings.Accept(toJsonVisitor)) {
                    file << json.dump(2);
                } else {
                    m_error = ::anar::service::ErrorManager::GenerateError(1, anar::constant::ErrorLevel::ANAR_HIGH_ERROR, "Error on write settings file");
                    m_error.SubErrors.emplace_back(*(toJsonVisitor.Error()));
                }
            } else {
                m_error = ::anar::service::ErrorManager::GenerateError(1, anar::constant::ErrorLevel::ANAR_HIGH_ERROR, "Error on open settings file");
            }
        } catch (std::exception& exception) {
            m_error = ::anar::service::ErrorManager::GenerateError(1, anar::constant::ErrorLevel::ANAR_HIGH_ERROR, "Error on write settings file: " + std::string(exception.what()));
        }
        return ::anar::service::ErrorManager::HaveNoError(m_error);
    }
}  // namespace anar::parspark::service
