#ifndef VIEW_SETTING_VIEW_HPP
#define VIEW_SETTING_VIEW_HPP

#include <QJSEngine>
#include <QQmlEngine>
#include <QVariantMap>
#include <control/settings-controller.hpp>
#include <view/base-view.hpp>

namespace parspark::view {
   class SettingsView;
   using SettingsViewPtr = std::shared_ptr<SettingsView>;
   class SettingsView : public BaseView {
      Q_OBJECT
      Q_PROPERTY(QVariantMap settingsInfo MEMBER m_settingsInfo NOTIFY
                     settingsInfoChanged)
      Q_PROPERTY(QStringList serialPorts MEMBER m_serialPorts NOTIFY
                     serialPortsChanged)

    public:
      static SettingsViewPtr Create();
      explicit SettingsView(QObject* parent = nullptr);
      static QObject* SettingViewObjectProvider(QQmlEngine* engine,
                                              QJSEngine* scriptEngine);

      QVariantMap settingsInfo() const {
         return m_settingsInfo;
      }
      void setSettingsInfo(const QVariantMap& settingsInfo) {
         m_settingsInfo = settingsInfo;
      }

    signals:
        void settingsInfoChanged(QVariantMap settingsInfo);
        void serialPortsChanged(QStringList serialPorts);

    public slots:
      void loadSettingsInfo();
      void saveSettings(QVariantMap settingsInfo);
      void getSerialPorts();

    private:
      QVariantMap m_settingsInfo;
      QStringList m_serialPorts;
      control::SettingsControllerPtr m_settingsController{
          new control::SettingsController};
   };
} // namespace parspark::view
#endif // VIEW_SETTING_VIEW_HPP
