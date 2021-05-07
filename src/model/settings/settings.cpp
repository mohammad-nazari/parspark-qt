#include "settings.hpp"

namespace anar::model {
   SettingsPtr Settings::Create() {
      return std::make_shared<Settings>();
   }
   Settings::Settings()
       : Model("Setting") {
   }

   bool Settings::FromJson(const json_nlohmann& json) {
      Model::FromJson(json);
      m_settingAlpr->FromJson(json["alpr"]);
      m_settingBoard->FromJson(json["board"]);
      m_settingCamera->FromJson(json["camera"]);
      m_settingCardReader->FromJson(json["cardReader"]);
      m_settingDataBase->FromJson(json["dataBase"]);
      m_settingGate->FromJson(json["gate"]);
      m_settingParking->FromJson(json["parking"]);
      m_settingPayment->FromJson(json["payment"]);
      m_settingSoftware->FromJson(json["software"]);
      m_settingPrinter->FromJson(json["printer"]);
      return true;
   }
   json_nlohmann Settings::ToJson() {
      json_nlohmann json = Model::ToJson();
      json["alpr"] = m_settingAlpr->ToJson();
      json["board"] = m_settingBoard->ToJson();
      json["camera"] = m_settingCamera->ToJson();
      json["cardReader"] = m_settingCardReader->ToJson();
      json["dataBase"] = m_settingDataBase->ToJson();
      json["gate"] = m_settingGate->ToJson();
      json["parking"] = m_settingParking->ToJson();
      json["payment"] = m_settingPayment->ToJson();
      json["software"] = m_settingSoftware->ToJson();
      json["printer"] = m_settingPrinter->ToJson();
      return json;
   }
}  // namespace anar::model
