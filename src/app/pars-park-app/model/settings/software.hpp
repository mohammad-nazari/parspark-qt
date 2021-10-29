#ifndef ANAR_SOFTWARE_HPP
#define ANAR_SOFTWARE_HPP

#include "anar/model/model.hpp"
#include "server.hpp"

namespace anar::model {
   class Software;
   using SoftwarePtr = std::shared_ptr<Software>;
   class Software : public Model {
     public:
      static SoftwarePtr Create();
      Software();

      bool FromJson(const json_nlohmann& json);
      json_nlohmann ToJson();

      [[nodiscard]] bool ActiveEnter() const {
         return m_activeEnter;
      }
      void ActiveEnter(bool activeEnter) {
         m_activeEnter = activeEnter;
      }
      [[nodiscard]] bool ActiveExit() const {
         return m_activeExit;
      }
      void ActiveExit(bool activeExit) {
         m_activeExit = activeExit;
      }
      [[nodiscard]] bool AsServer() const {
         return m_asServer;
      }
      void AsServer(bool asServer) {
         m_asServer = asServer;
      }
      [[nodiscard]] uint16_t Port() const {
         return m_port;
      }
      void Port(uint16_t port) {
         m_port = port;
      }
      [[nodiscard]] const ServerPtr& ServerAddress() const {
         return m_serverAddress;
      }
      void ServerAddress(const ServerPtr& serverAddress) {
         m_serverAddress = serverAddress;
      }

     private:
      bool m_activeEnter{false};
      bool m_activeExit{false};
      bool m_asServer{true};
      uint16_t m_port{50001};
      ServerPtr m_serverAddress{new Server};
   };
}  // namespace anar::model
#endif  // ANAR_SOFTWARE_HPP
