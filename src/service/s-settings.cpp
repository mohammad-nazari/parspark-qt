#include "s-settings.hpp"

#include <fstream>
#include <memory>

namespace anar::service {
   SSettingsPtr SSettings::_instance = nullptr;

   SSettings::SSettings() = default;
   SSettingsPtr SSettings::Instance() {
      if (_instance == nullptr) {
         _instance.reset(new SSettings);
         _instance->Load();
      }
      return _instance;
   }
   void SSettings::Destroy() {
      if (_instance != nullptr) {
         _instance = nullptr;
      }
   }

   bool SSettings::Load(const std::string& address) {
      try {
         std::ifstream file(address, std::ios::in);
         if (file.is_open()) {
            std::string data = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            if (!m_settings->FromJsonString(data)) {
               m_error = "Error on parse settings data";
            }
         } else {
            m_error = "Error on open settings file";
         }
      } catch (std::exception& exception) {
         m_error = "Error on read settings file";
      }
      return m_error.empty();
   }
   bool SSettings::Save(const std::string& address) {
      try {
         m_error.clear();
         std::ofstream file(address, std::ios::out);
         if (file.is_open()) {
            file << m_settings->ToJsonString();
         } else {
            m_error = "Error on open settings file";
         }
      } catch (std::exception& exception) {
         m_error = "Error on write settings file: " + std::string(exception.what());
      }
      return m_error.empty();
   }
}  // namespace anar::service
