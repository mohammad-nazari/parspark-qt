#include "alpr.hpp"

namespace parspark::model {
   AlprByCameraPtr AlprByCamera::Create() {
      return std::make_shared<AlprByCamera>();
   }
   AlprByCamera::AlprByCamera()
       : BaseModel("AlprByCamera") {
   }

   bool AlprByCamera::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_submitWithoutEnterPlate = json["submitWithoutEnterPlate"].toBool();
      m_submitWithoutExitPlate = json["submitWithoutExitPlate"].toBool();
      return true;
   }
   const QVariantMap AlprByCamera::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enable"] = m_enable;
      json["submitWithoutEnterPlate"] = m_submitWithoutEnterPlate;
      json["submitWithoutExitPlate"] = m_submitWithoutExitPlate;
      return json;
   }

   AlprPtr Alpr::Create() {
      return std::make_shared<Alpr>();
   }
   Alpr::Alpr()
       : BaseModel("Alpr") {
   }

   bool Alpr::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_byCamera->FromJson(json["byCamera"].toMap());
      return true;
   }
   const QVariantMap Alpr::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enable"] = m_enable;
      json["byCamera"] = m_byCamera->ToJson();
      return json;
   }
} // namespace parspark::model
