#ifndef ANAR_PARS_PARK_CONTROLLER_SETTINGS_HPP
#define ANAR_PARS_PARK_CONTROLLER_SETTINGS_HPP

#include "anar/controller.hpp"
#include "model/settings/settings-model.hpp"

namespace anar::parspark::controller {
   class SettingsController;
   using SettingsControllerPtr = std::shared_ptr<SettingsController>;
   class SettingsController : public anar::controller::Controller {
     public:
      static SettingsControllerPtr Create();
      explicit SettingsController();
      ~SettingsController() override = default;

      model::SettingsModel Load();
      bool Save(const model::SettingsModel& settings);
   };
}  // namespace anar::parspark::controller

#endif  // ANAR_PARS_PARK_CONTROLLER_SETTINGS_HPP
