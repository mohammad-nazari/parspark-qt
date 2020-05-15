#include "settings-view.hpp"

#include <QDebug>
#include <control/settings-controller.hpp>

namespace parspark::view {
   SettingsViewPtr SettingsView::Create() {
      return std::make_shared<SettingsView>();
   }
   SettingsView::SettingsView(QObject* parent)
       : BaseView(parent) {
   }
   QObject* SettingsView::SettingViewObjectProvider(QQmlEngine* engine,
                                                    QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)

      return new SettingsView;
   }

   void SettingsView::loadSettingsInfo() {
      m_settingsInfo = m_settingsController->Load()->ToJson();
   }
   void SettingsView::saveSettings(QVariantMap settingsInfo) {
      m_settingsInfo = settingsInfo;
      // ToDO: validate settings
      // Save settings
      model::SettingsPtr settings{new model::Settings};
      m_done = settings->FromJson(m_settingsInfo);
      if (!m_done) {
         m_error = settings->Error();
         return;
      }
      m_done = m_settingsController->Save(settings);
      if (!m_done) {
         m_error = m_settingsController->Error();
      }
   }
   void SettingsView::getSerialPorts() {
      m_serialPorts = m_settingsController->GetSerialPortListNames();
   }
} // namespace parspark::view
