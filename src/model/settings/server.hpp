#ifndef MODEL_SERVER_HPP
#define MODEL_SERVER_HPP

#include <model/base-model.hpp>

namespace parspark::model {
   class Server;
   using ServerPtr = std::shared_ptr<Server>;
   class Server : public BaseModel {
    public:
      static ServerPtr Create();
      Server();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      QString Address() const {
         return m_address;
      }
      void Address(const QString& address) {
         m_address = address;
      }
      uint16_t Port() const {
         return m_port;
      }
      void Port(const uint16_t& port) {
         m_port = port;
      }

    private:
      QString m_address{"localhost"};
      uint16_t m_port{50001};
   };
} // namespace parspark::model
#endif // MODEL_SERVER_HPP
