#include "settings-view.hpp"

#include <QDebug>
#include <utility>

#include "service/qt-std-converter.hpp"

namespace anar::view {
   SettingsViewPtr SettingsView::Create() {
      return std::make_shared<SettingsView>();
   }
   SettingsView::SettingsView(QObject* parent)
       : BaseView(parent) {
   }
   QObject* SettingsView::SettingViewObjectProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)

      return new SettingsView;
   }

   void SettingsView::loadSettings() {
      m_settingsInfo = service::QtStdConverter::JsonToQVariantMap(m_settingsController->Load()->ToJson());
   }
   void SettingsView::saveSettings(QVariantMap settingsInfo) {
      m_settingsInfo = std::move(settingsInfo);
      // ToDO: validate settings
      // Save settings
      model::SettingsPtr settings{new model::Settings};
      m_done = settings->FromJson(service::QtStdConverter::QVariantMapToJson(m_settingsInfo));
      if (!m_done) {
         m_error = settings->Error().c_str();
         return;
      }
      m_done = m_settingsController->Save(settings);
      if (!m_done) {
         m_error = m_settingsController->Error().c_str();
      }
   }
}  // namespace anar::view
