#include "gate.hpp"

namespace parspark::model {
   GateInfo::GateInfo()
       : BaseModel("Gate") {
   }

   bool GateInfo::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_address->FromJson(json["address"].toMap());
      m_openAuto = json["openAuto"].toBool();
      m_closeAuto = json["closeAuto"].toBool();
      m_closeAfter = json["closeAfter"].toInt();
      return true;
   }
   const QVariantMap GateInfo::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enable"] = m_enable;
      json["address"] = m_address->ToJson();
      json["openAuto"] = m_openAuto;
      json["closeAuto"] = m_closeAuto;
      json["closeAfter"] = m_closeAfter;
      return json;
   }

   Gate::Gate()
       : BaseModel("Gate") {
   }

   bool Gate::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enter->FromJson(json["enter"].toMap());
      m_exit->FromJson(json["exit"].toMap());
      return true;
   }
   const QVariantMap Gate::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enter"] = m_enter->ToJson();
      json["exit"] = m_exit->ToJson();
      return json;
   }
} // namespace parspark::model
