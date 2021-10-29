#ifndef ANAR_PARS_PARK_SERVICE_S_SETTING_HPP
#define ANAR_PARS_PARK_SERVICE_S_SETTING_HPP

#include "model/settings/settings.hpp"

namespace anar::service {
   class SSettings;
   using SSettingsPtr = std::shared_ptr<SSettings>;
   using SSettingsUPtr = std::unique_ptr<SSettings>;
   using SSettingsWPtr = std::weak_ptr<SSettings>;
   class SSettings {
     public:
      static SSettingsPtr Instance();
      static void Destroy();
      SSettings(SSettingsPtr const&) = delete;
      ~SSettings() {
         Destroy();
      }

      void operator=(SSettingsPtr const&) = delete;

      bool Load(const std::string& address = "settings.json");
      bool Save(const std::string& address = "settings.json");

      const model::DataBaseModelPtr& DataBase() {
         return m_settings->SettingDataBase();
      }
      void DataBase(const model::DataBaseModelPtr& dataBase) {
         m_settings->SettingDataBase(dataBase);
      }

      [[nodiscard]] const model::SettingsPtr& Settings() const {
         return m_settings;
      }
      void Settings(const model::SettingsPtr& settings) {
         m_settings = settings;
      }
      [[nodiscard]] const std::string& Error() const {
         return m_error;
      }
      void Error(const std::string& error) {
         m_error = error;
      }

     private:
      SSettings();
      static SSettingsPtr _instance;

      model::SettingsPtr m_settings{new model::Settings};
      std::string m_error;
   };
}  // namespace anar::service
#endif  // ANAR_PARS_PARK_SERVICE_S_SETTING_HPP
