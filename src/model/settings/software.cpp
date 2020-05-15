#include "software.hpp"

namespace parspark::model {
   SoftwarePtr Software::Create() {
      return std::make_shared<Software>();
   }

   Software::Software()
       : BaseModel("Software") {
   }

   bool Software::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_activeEnter = json["activeEnter"].toBool();
      m_activeExit = json["activeExit"].toBool();
      m_asServer = json["asServer"].toBool();
      m_port = json["port"].toUInt();
      m_serverAddress->FromJson(json["serverAddress"].toMap());
      return true;
   }
   const QVariantMap Software::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["activeEnter"] = m_activeEnter;
      json["activeExit"] = m_activeExit;
      json["asServer"] = m_asServer;
      json["port"] = m_port;
      json["serverAddress"] = m_serverAddress->ToJson();
      return json;
   }
} // namespace parspark::model
