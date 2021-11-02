#include "settings-view.hpp"

#include "service/qt-std-converter.hpp"

namespace anar::parspark::view {
   SettingsView* SettingsView::m_instance = nullptr;
   SettingsView* SettingsView::QmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)
      if (!m_instance) {
         m_instance = new SettingsView();
      }
      return m_instance;
   }
   SettingsView::SettingsView(QObject* parent)
       : View(parent) {
   }

   void SettingsView::loadSettings() {
      //      m_settingsInfo = service::QtStdConverter::JsonToQVariantMap(m_settingsController->Load()->ToJson());
   }
   void SettingsView::saveSettings(QVariantMap settingsInfo) {
      m_settingsInfo = std::move(settingsInfo);
      // ToDO: validate settings
      // Save settings
      model::SettingsModel settings;
//      if (!settings->FromJson(service::QtStdConverter::QVariantMapToJson(m_settingsInfo))) {
//         //         m_error = settings->Error().c_str();
//         return;
//      }
      if (!m_settingsController->Save(settings)) {
         //         m_error = m_settingsController->Error().c_str();
      }
   }
}  // namespace anar::parspark::view
