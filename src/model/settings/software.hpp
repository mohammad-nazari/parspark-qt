#ifndef SOFTWARE_HPP
#define SOFTWARE_HPP

#include "server.hpp"
#include <model/base-model.hpp>

namespace parspark::model {
   class Software;
   using SoftwarePtr = std::shared_ptr<Software>;
   class Software : public BaseModel {
    public:
      static SoftwarePtr Create();
      Software();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool ActiveEnter() const {
         return m_activeEnter;
      }
      void ActiveEnter(bool activeEnter) {
         m_activeEnter = activeEnter;
      }
      bool ActiveExit() const {
         return m_activeExit;
      }
      void ActiveExit(bool activeExit) {
         m_activeExit = activeExit;
      }
      bool AsServer() const {
         return m_asServer;
      }
      void AsServer(bool asServer) {
         m_asServer = asServer;
      }
      uint16_t Port() const {
         return m_port;
      }
      void Port(const uint16_t& port) {
         m_port = port;
      }
      ServerPtr ServerAddress() const {
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
} // namespace parspark::model
#endif // SOFTWARE_HPP
