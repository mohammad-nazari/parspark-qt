#include "settings-view.hpp"

#include "nlohmann/json.hpp"
#include "service/model-binding/json/from-json-visitor.hpp"
#include "service/model-binding/json/to-json-visitor.hpp"
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
        nlohmann::ordered_json json;
        service::ToJsonVisitor toJsonVisitor(json);
        if (m_settingsController->Load().Accept(toJsonVisitor)) {
            m_settingsInfo = service::QtStdConverter::JsonToQVariantMap(json);
        }
    }
    void SettingsView::saveSettings(QVariantMap settingsInfo) {
        m_error.clear();
        m_settingsInfo = std::move(settingsInfo);
        // ToDO: validate settings
        // Save settings
        model::SettingsModel settings;
        nlohmann::ordered_json json = service::QtStdConverter::QVariantMapToJson(m_settingsInfo);
        service::FromJsonVisitor fromJsonVisitor(json);
        if (!settings.Accept(fromJsonVisitor)) {
            m_error = fromJsonVisitor.Error()->Message.c_str();
        } else if (!m_settingsController->Save(settings)) {
            m_error = m_settingsController->Error().Message.c_str();
        }
    }
}  // namespace anar::parspark::view
