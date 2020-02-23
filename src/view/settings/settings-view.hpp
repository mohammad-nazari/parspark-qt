#ifndef SETTINGVIEW_HPP
#define SETTINGVIEW_HPP

#include <QObject>
#include <QVariantMap>

namespace parspark::view {
   class SettingsView : public QObject {
      Q_OBJECT
      Q_PROPERTY(QVariantMap settingsInfo READ settingsInfo WRITE
                     setSettingsInfo NOTIFY settingsInfoChanged)

    public:
      explicit SettingsView(QObject* parent = nullptr);

      QVariantMap settingsInfo() const {
         return m_settingsInfo;
      }
      void setSettingsInfo(const QVariantMap& settingsInfo) {
         m_settingsInfo = settingsInfo;
      }

    signals:
      void settingsInfoChanged();

    public slots:
      void loadSettingsInfo();

    private:
      QVariantMap m_settingsInfo;
   };
} // namespace parspark::view
#endif // SETTINGVIEW_HPP
