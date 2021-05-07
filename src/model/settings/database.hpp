#ifndef ANAR_DATABASE_HPP
#define ANAR_DATABASE_HPP

#include "model/model.hpp"

namespace anar::model {
   class DataBase;
   using DataBasePtr = std::shared_ptr<DataBase>;
   class DataBase : public Model {
     public:
      static DataBasePtr Create();
      DataBase();

      bool FromJson(const json_nlohmann& json) final;
      json_nlohmann ToJson() final;

      [[nodiscard]] const std::string& HostAddress() const {
         return m_hostAddress;
      }
      void HostAddress(const std::string& hostAddress) {
         m_hostAddress = hostAddress;
      }
      [[nodiscard]] const std::string& UserName() const {
         return m_userName;
      }
      void UserName(const std::string& userName) {
         m_userName = userName;
      }
      [[nodiscard]] const std::string& PassWord() const {
         return m_passWord;
      }
      void Password(const std::string& passWord) {
         m_passWord = passWord;
      }
      [[nodiscard]] uint16_t Port() const {
         return m_port;
      }
      void Port(uint16_t port) {
         m_port = port;
      }
      [[nodiscard]] const std::string& DatabaseName() const {
         return m_databaseName;
      }
      void DatabaseName(const std::string& databaseName) {
         m_databaseName = databaseName;
      }

     protected:
      std::string m_engineName{};
      std::string m_hostAddress{"localhost"};
      std::string m_userName{"root"};
      std::string m_passWord{"root"};
      uint16_t m_port{3306};  // Mysql default port
      std::string m_databaseName{"parspark"};
   };
}  // namespace anar::model
#endif  // ANAR_DATABASE_HPP
