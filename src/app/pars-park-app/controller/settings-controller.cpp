#include "settings-controller.hpp"

#include "anar/error-manager.hpp"
#include "anar/serial-port.hpp"
#include "service/s-settings.hpp"

namespace anar::parspark::controller {
    SettingsControllerPtr SettingsController::Create() {
        return std::make_shared<SettingsController>();
    }
    SettingsController::SettingsController()
        : Controller() {
    }

    model::SettingsModel SettingsController::Load() {
        return service::SSettings::Instance()->Settings();
    }
    bool SettingsController::Save(const model::SettingsModel& settings) {
        ::anar::service::ErrorManager::ResetError(m_error);
        service::SSettings::Instance()->Settings(settings);
        if (service::SSettings::Instance()->Save()) {
            m_error = service::SSettings::Instance()->Error();
        }
        return ::anar::service::ErrorManager::HaveNoError(m_error);
    }
}  // namespace anar::parspark::controller
