#include "settings-controller.hpp"

#include "service/s-settings.hpp"
#include "service/serial-port.hpp"

namespace anar::controller {
   SettingsControllerPtr SettingsController::Create() {
      return std::make_shared<SettingsController>();
   }
   SettingsController::SettingsController() : Controller() {
   }

   model::SettingsPtr SettingsController::Load() {
      return service::SSettings::Instance()->Settings();
   }
   bool SettingsController::Save(const model::SettingsPtr& settings) {
      service::SSettings::Instance()->Settings(settings);
      auto isSaved = service::SSettings::Instance()->Save();
      if (isSaved) {
         m_error = service::SSettings::Instance()->Error();
      }
      return isSaved;
   }
}  // namespace anar::controller
