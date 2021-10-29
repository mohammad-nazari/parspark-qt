#include "gate.hpp"

namespace anar::model {
   GateInfoPtr GateInfo::Create() {
      return anar::model::GateInfoPtr();
   }
   GateInfo::GateInfo()
       : Model("Gate") {
   }

   bool GateInfo::FromJson(const json_nlohmann& json) {

      m_enable = json["enable"];
      m_address->FromJson(json["address"]);
      m_openAuto = json["openAuto"];
      m_closeAuto = json["closeAuto"];
      m_closeAfter = json["closeAfter"];
      return true;
   }
   json_nlohmann GateInfo::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["address"] = m_address->ToJson();
      json["openAuto"] = m_openAuto;
      json["closeAuto"] = m_closeAuto;
      json["closeAfter"] = m_closeAfter;
      return json;
   }

   GatePtr Gate::Create() {
      return anar::model::GatePtr();
   }
   Gate::Gate()
       : Model("Gate") {
   }

   bool Gate::FromJson(const json_nlohmann& json) {

      m_enter->FromJson(json["enter"]);
      m_exit->FromJson(json["exit"]);
      return true;
   }
   json_nlohmann Gate::ToJson() {
      json_nlohmann json;
      json["enter"] = m_enter->ToJson();
      json["exit"] = m_exit->ToJson();
      return json;
   }
}  // namespace anar::model
