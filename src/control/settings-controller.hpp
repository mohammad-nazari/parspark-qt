#ifndef SETTING_CONTROLLER_HPP
#define SETTING_CONTROLLER_HPP

#include <QFile>
#include <QObject>
#include <model/settings/settings.hpp>

namespace parspark::control {
   class SSettingsController;
   using SSettingsControllerPtr = std::shared_ptr<SSettingsController>;
   class SSettingsController : public QObject {
      Q_OBJECT
    public:
      static SSettingsControllerPtr _instance;

      static SSettingsControllerPtr Instance() {
         if (_instance == nullptr) {
            _instance = SSettingsControllerPtr(new SSettingsController);
         }
         return _instance;
      }
      ~SSettingsController() {
      }

      static void Load(const QString& address = "settings.json");
      static void Save(const QString& address = "settings.json");

      static model::SettingsPtr Settings() {
         return _settings;
      }
      static void Settings(const model::SettingsPtr& settings) {
         _settings = settings;
      }

      static model::DataBasePtr DataBase(){
          return _settings->SettingDataBase();
      }
      static void DataBase(const model::DataBasePtr &dataBase){
          _settings->SettingDataBase(dataBase);
      }

    private:
      explicit SSettingsController(QObject* parent = nullptr);
      static model::SettingsPtr _settings;
   };
} // namespace parspark::control
#endif // SETTING_CONTROLLER_HPP
