#ifndef MODEL_DATABASE_HPP
#define MODEL_DATABASE_HPP

#include <model/base-model.hpp>

namespace parspark::model {
   class DataBase;
   using DataBasePtr = std::shared_ptr<DataBase>;
   class DataBase : public BaseModel {
    public:
      static DataBasePtr Create();
      DataBase();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      QString Address() const {
         return m_address;
      }
      void Address(const QString& address) {
         m_address = address;
      }
      QString UserName() const {
         return m_userName;
      }
      void UserName(const QString& userName) {
         m_userName = userName;
      }
      QString Password() const {
         return m_password;
      }
      void Password(const QString& password) {
         m_password = password;
      }
      uint16_t Port() const {
         return m_port;
      }
      void Port(const uint16_t& port) {
         m_port = port;
      }
      QString DatabaseName() const {
         return m_databaseName;
      }
      void DatabaseName(const QString& databaseName) {
         m_databaseName = databaseName;
      }

    protected:
      QString m_address{"localhost"};
      QString m_userName{"root"};
      QString m_password{"root"};
      uint16_t m_port{3306}; // Mysql default port
      QString m_databaseName{"parspark"};
   };
} // namespace parspark::model
#endif // MODEL_DATABASE_HPP
