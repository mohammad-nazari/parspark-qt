#ifndef CONTROL_SETTINGS_CONTROLLER_HPP
#define CONTROL_SETTINGS_CONTROLLER_HPP

#include "base-controller.hpp"
#include <model/settings/settings.hpp>

namespace parspark::control {
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
      QStringList GetSerialPortListNames();
   };
} // namespace parspark::control

#endif // CONTROL_SETTINGS_CONTROLLER_HPP
