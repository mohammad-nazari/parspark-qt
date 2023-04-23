#ifndef ANAR_PARS_PARK_SERVICE_S_SETTING_HPP
#define ANAR_PARS_PARK_SERVICE_S_SETTING_HPP

#include "anar/error-model.hpp"
#include "model/settings/settings-model.hpp"

namespace anar::parspark::service {
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

        const anar::common::model::DataBaseModel& DataBase() {
            return m_settings.DataBase;
        }
        void DataBase(const anar::common::model::DataBaseModel& dataBase) {
            m_settings.DataBase = dataBase;
        }

        [[nodiscard]] const model::SettingsModel& Settings() const {
            return m_settings;
        }
        void Settings(const model::SettingsModel& settings) {
            m_settings = settings;
        }
        [[nodiscard]] const anar::common::model::ErrorModel& Error() const {
            return m_error;
        }
        void Error(const anar::common::model::ErrorModel& error) {
            m_error = error;
        }

       private:
        SSettings();
        static SSettingsPtr _instance;

        model::SettingsModel m_settings;
        anar::common::model::ErrorModel m_error;
    };
}  // namespace anar::parspark::service
#endif  // ANAR_PARS_PARK_SERVICE_S_SETTING_HPP
