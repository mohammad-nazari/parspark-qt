#ifndef ANAR_SERVER_HPP
#define ANAR_SERVER_HPP

#include "model/base-model.hpp"

namespace anar::model {
   class Server;
   using ServerPtr = std::shared_ptr<Server>;
   class Server : public BaseModel {
     public:
      static ServerPtr Create();
      Server();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const std::string& Address() const {
         return m_address;
      }
      void Address(const std::string& address) {
         m_address = address;
      }
      [[nodiscard]] uint16_t Port() const {
         return m_port;
      }
      void Port(uint16_t port) {
         m_port = port;
      }

     private:
      std::string m_address{"localhost"};
      uint16_t m_port{50001};
   };
}  // namespace anar::model
#endif  // ANAR_SERVER_HPP
