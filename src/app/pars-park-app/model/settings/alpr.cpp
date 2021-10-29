#include "alpr.hpp"

namespace anar::model {
   AlprByCameraPtr AlprByCamera::Create() {
      return std::make_shared<AlprByCamera>();
   }
   AlprByCamera::AlprByCamera()
       : Model("AlprByCamera", "Alpr By  Camera") {
   }

   bool AlprByCamera::FromJson(const json_nlohmann& json) {
      m_enable = json["enable"];
      m_submitWithoutEnterPlate = json["submitWithoutEnterPlate"];
      m_submitWithoutExitPlate = json["submitWithoutExitPlate"];
      return true;
   }
   json_nlohmann AlprByCamera::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["submitWithoutEnterPlate"] = m_submitWithoutEnterPlate;
      json["submitWithoutExitPlate"] = m_submitWithoutExitPlate;
      return json;
   }

   AlprPtr Alpr::Create() {
      return std::make_shared<Alpr>();
   }
   Alpr::Alpr()
       : Model("Alpr", "Alpr") {
   }

   bool Alpr::FromJson(const json_nlohmann& json) {
      m_enable = json["enable"];
      m_byCamera->FromJson(json["byCamera"]);
      return true;
   }
   json_nlohmann Alpr::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["byCamera"] = m_byCamera->ToJson();
      return json;
   }
}  // namespace anar::model
