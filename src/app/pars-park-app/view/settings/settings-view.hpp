#ifndef VIEW_SETTING_VIEW_HPP
#define VIEW_SETTING_VIEW_HPP

#include <QJSEngine>
#include <QQmlEngine>
#include <QVariantMap>

#include "controller/settings-controller.hpp"
#include "view/view.hpp"

namespace anar::parspark::view {
   class SettingsView;
   using SettingsViewPtr = std::shared_ptr<SettingsView>;
   class SettingsView : public View {
      Q_OBJECT
      Q_PROPERTY(QVariantMap settingsInfo MEMBER m_settingsInfo NOTIFY settingsInfoChanged)

     public:
      static SettingsViewPtr Create();
      explicit SettingsView(QObject* parent = nullptr);
      static QObject* SettingViewObjectProvider(QQmlEngine* engine, QJSEngine* scriptEngine);

      QVariantMap settingsInfo() const {
         return m_settingsInfo;
      }
      void setSettingsInfo(const QVariantMap& settingsInfo) {
         m_settingsInfo = settingsInfo;
      }

     signals:
      void settingsInfoChanged(QVariantMap settingsInfo);

     public slots:
      void loadSettings();
      void saveSettings(QVariantMap settingsInfo);

     private:
      QVariantMap m_settingsInfo;
      controller::SettingsControllerPtr m_settingsController{new controller::SettingsController};
   };
}  // namespace anar::view
#endif  // VIEW_SETTING_VIEW_HPP
