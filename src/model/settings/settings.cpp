#include "settings.hpp"

namespace parspark::model {
   SettingsPtr Settings::Create() {
      return std::make_shared<Settings>();
   }
   Settings::Settings()
       : BaseModel("Setting") {
   }

   bool Settings::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_settingAlpr->FromJson(json["alpr"].toMap());
      m_settingBoard->FromJson(json["board"].toMap());
      m_settingCamera->FromJson(json["camera"].toMap());
      m_settingCardReader->FromJson(json["cardReader"].toMap());
      m_settingDataBase->FromJson(json["dataBase"].toMap());
      m_settingGate->FromJson(json["gate"].toMap());
      m_settingParking->FromJson(json["parking"].toMap());
      m_settingPayment->FromJson(json["payment"].toMap());
      m_settingSoftware->FromJson(json["software"].toMap());
      return true;
   }
   const QVariantMap Settings::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["alpr"] = m_settingAlpr->ToJson();
      json["board"] = m_settingBoard->ToJson();
      json["camera"] = m_settingCamera->ToJson();
      json["cardReader"] = m_settingCardReader->ToJson();
      json["dataBase"] = m_settingDataBase->ToJson();
      json["gate"] = m_settingGate->ToJson();
      json["parking"] = m_settingParking->ToJson();
      json["payment"] = m_settingPayment->ToJson();
      json["software"] = m_settingSoftware->ToJson();
      return json;
   }
} // namespace parspark::model
