#ifndef ANAR_PARS_PARK_VIEW_SETTING_HPP
#define ANAR_PARS_PARK_VIEW_SETTING_HPP

#include <QVariantMap>

#include "controller/settings-controller.hpp"
#include "view/view.hpp"

namespace anar::parspark::view {
    class SettingsView;
    using SettingsViewPtr = std::shared_ptr<SettingsView>;
    class SettingsView : public View {
        Q_OBJECT
        Q_DISABLE_COPY(SettingsView)
        Q_PROPERTY(QVariantMap settingsInfo MEMBER m_settingsInfo NOTIFY settingsInfoChanged)

       public:
        static SettingsView* QmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine);

        explicit SettingsView(QObject* parent = nullptr);

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
        static SettingsView* m_instance;
        QVariantMap m_settingsInfo;
        controller::SettingsControllerPtr m_settingsController{new controller::SettingsController};
    };
}  // namespace anar::parspark::view
#endif  // ANAR_PARS_PARK_VIEW_SETTING_HPP
