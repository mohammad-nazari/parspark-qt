#include "settings-controller.hpp"

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
      service::SSettings::Instance()->Settings(settings);
      auto isSaved = service::SSettings::Instance()->Save();
      if (isSaved) {
         //         m_error = service::SSettings::Instance()->Error();
      }
      return isSaved;
   }
}  // namespace anar::parspark::controller
