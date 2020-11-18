#ifndef ANAR_SETTINGS_CONTROLLER_HPP
#define ANAR_SETTINGS_CONTROLLER_HPP

#include "base-controller.hpp"
#include "model/settings/settings.hpp"

namespace anar::controller {
   class SettingsController;
   using SettingsControllerPtr = std::shared_ptr<SettingsController>;
   class SettingsController : public BaseController {
     public:
      static SettingsControllerPtr Create();
      explicit SettingsController();
      ~SettingsController() {
      }

      model::SettingsPtr Load();
      bool Save(const model::SettingsPtr& settings);
   };
}  // namespace anar::controller

#endif  // ANAR_SETTINGS_CONTROLLER_HPP
