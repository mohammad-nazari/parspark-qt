#include "s-settings.hpp"

#include <QFile>

namespace parspark::service {
   SSettingsUPtr SSettings::_instance = nullptr;

   SSettings& SSettings::Instance() {
      if (_instance == nullptr) {
         _instance.reset(new SSettings);
      }
      return *_instance;
   }
   void SSettings::Destroy() {
      if (_instance != nullptr) {
         _instance.reset(nullptr);
      }
   }

   bool SSettings::Load(const QString& address) {
      try {
         QFile file(address);
         if (file.open(QFile::ReadOnly)) {
            QString data = file.readAll();
            if (!m_settings->FromString(data)) {
               m_error = "Error on parse settings data";
            }
         } else {
            m_error = "Error on open settings file";
         }
      } catch (std::exception& exception) {
         m_error = "Error on read settings file";
      }
      return m_error.isEmpty();
   }
   bool SSettings::Save(const QString& address) {
      try {
         m_error.clear();
         QFile file(address);
         if (file.open(QFile::WriteOnly)) {
            if (file.write(m_settings->ToString().toStdString().c_str()) <= 0) {
               m_error = "Error on save settings data";
            }
         } else {
            m_error = "Error on open settings file";
         }
      } catch (std::exception& exception) {
         m_error = "Error on write settings file";
      }
      return m_error.isEmpty();
   }

   SSettings::SSettings() {
      Load();
   }
} // namespace parspark::service
