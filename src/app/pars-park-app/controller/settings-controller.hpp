#ifndef ANAR_PARS_PARK_CONTROLLER_SETTINGS_HPP
#define ANAR_PARS_PARK_CONTROLLER_SETTINGS_HPP

#include "anar/controller/controller.hpp"
#include "model/settings/settings.hpp"

namespace anar::controller {
   class SettingsController;
   using SettingsControllerPtr = std::shared_ptr<SettingsController>;
   class SettingsController : public Controller {
     public:
      static SettingsControllerPtr Create();
      explicit SettingsController();
      ~SettingsController() {
      }

      model::SettingsPtr Load();
      bool Save(const model::SettingsPtr& settings);
   };
}  // namespace anar::controller

#endif  // ANAR_PARS_PARK_CONTROLLER_SETTINGS_HPP
