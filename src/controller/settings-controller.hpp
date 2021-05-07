#ifndef ANAR_SETTINGS_CONTROLLER_HPP
#define ANAR_SETTINGS_CONTROLLER_HPP

#include "controller.hpp"
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

#endif  // ANAR_SETTINGS_CONTROLLER_HPP
