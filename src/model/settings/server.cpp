#include "server.hpp"

namespace parspark::model {
   ServerPtr Server::Create() {
      return std::make_shared<Server>();
   }
   Server::Server()
       : BaseModel("Server") {
   }

   bool Server::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_address = json["address"].toString();
      m_port = json["port"].toUInt();
      return true;
   }
   const QVariantMap Server::ToJson() const {
      QVariantMap json;
      json["address"] = m_address;
      json["port"] = m_port;
      return json;
   }
} // namespace parspark::model
