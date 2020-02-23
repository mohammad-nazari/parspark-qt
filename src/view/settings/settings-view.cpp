#include "settings-view.hpp"

#include <control/settings-controller.hpp>

namespace parspark::view {
   SettingsView::SettingsView(QObject* parent)
       : QObject(parent) {
   }
   void SettingsView::loadSettingsInfo() {
      m_settingsInfo =
          control::SSettingsController::Instance()->Settings()->ToJson();
      emit settingsInfoChanged();
   }
} // namespace parspark::view
