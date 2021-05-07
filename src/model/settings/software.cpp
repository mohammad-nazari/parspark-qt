#include "software.hpp"

namespace anar::model {
   SoftwarePtr Software::Create() {
      return std::make_shared<Software>();
   }

   Software::Software()
       : Model("Software") {
   }

   bool Software::FromJson(const json_nlohmann& json) {
      Model::FromJson(json);
      m_activeEnter = json["activeEnter"];
      m_activeExit = json["activeExit"];
      m_asServer = json["asServer"];
      m_port = json["port"];
      m_serverAddress->FromJson(json["serverAddress"]);
      return true;
   }
   json_nlohmann Software::ToJson() {
      json_nlohmann json = Model::ToJson();
      json["activeEnter"] = m_activeEnter;
      json["activeExit"] = m_activeExit;
      json["asServer"] = m_asServer;
      json["port"] = m_port;
      json["serverAddress"] = m_serverAddress->ToJson();
      return json;
   }
}  // namespace anar::model
