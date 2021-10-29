#include "server.hpp"

namespace anar::model {
   ServerPtr Server::Create() {
      return std::make_shared<Server>();
   }
   Server::Server()
       : Model("Server","Server") {
   }

   bool Server::FromJson(const json_nlohmann& json) {

      m_address = json["address"];
      m_port = json["port"];
      return true;
   }
   json_nlohmann Server::ToJson() {
      json_nlohmann json;
      ;
      json["address"] = m_address;
      json["port"] = m_port;
      return json;
   }
}  // namespace anar::model
