#include "settings-controller.hpp"
#include <QDebug>

namespace parspark::control {
   SSettingsControllerPtr SSettingsController::_instance = nullptr;
   model::SettingsPtr SSettingsController::_settings =
       model::Settings::Create();

   void SSettingsController::Load(const QString& address) {
      try {
         QFile file(address);
         if (file.open(QFile::ReadOnly)) {
            QString data = file.readAll();
            //             qDebug() << data;
            if (!_settings->FromString(data)) {
               qDebug() << "Error on parse settings data";
            }
         } else {
            qDebug() << "Error on open settings file";
         }
      } catch (std::exception& exception) {
         qDebug() << "Error on read settings file";
      }
   }

   void SSettingsController::Save(const QString& address) {
      try {
         QFile file(address);
         if (file.open(QFile::WriteOnly)) {
            if (file.write(_settings->ToString().toStdString().c_str()) <= 0) {
               qDebug() << "Error on save settings data";
            }
         } else {
            qDebug() << "Error on open settings file";
         }
      } catch (std::exception& exception) {
         qDebug() << "Error on write settings file";
      }
   }

   SSettingsController::SSettingsController(QObject* parent)
       : QObject(parent) {
   }
} // namespace parspark::control
