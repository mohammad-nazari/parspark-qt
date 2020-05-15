#ifndef SERVICE_S_SETTING_SERVICE_HPP
#define SERVICE_S_SETTING_SERVICE_HPP

#include <QString>
#include <model/settings/settings.hpp>

namespace parspark::service {
   class SSettings;
   using SSettingsUPtr = std::unique_ptr<SSettings>;
   class SSettings {
    public:
        static SSettings& Instance();
        static void Destroy();
      ~SSettings() {
      }

      bool Load(const QString& address = "settings.json");
      bool Save(const QString& address = "settings.json");

      model::SettingsPtr Settings() {
         return m_settings;
      }
      void Settings(const model::SettingsPtr& settings) {
         m_settings = settings;
      }
      model::DataBasePtr DataBase() {
         return m_settings->SettingDataBase();
      }
      void DataBase(const model::DataBasePtr& dataBase) {
         m_settings->SettingDataBase(dataBase);
      }
      QString Error() {
         return m_error;
      }
      void Error(const QString& error) {
         m_error = error;
      }

    private:
      static SSettingsUPtr _instance;
      explicit SSettings();

      model::SettingsPtr m_settings{new model::Settings};
      QString m_error;
   };
} // namespace parspark::service
#endif // SERVICE_S_SETTING_SERVICE_HPP
