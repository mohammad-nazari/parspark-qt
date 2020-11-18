#ifndef ANAR_LOGIN_HPP
#define ANAR_LOGIN_HPP

#include "settings/database.hpp"
#include "user.hpp"

namespace anar::model {
   class Login;
   using LoginPtr = std::shared_ptr<Login>;
   class Login : public BaseModel {
     public:
      static LoginPtr Create();
      Login();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const UserPtr& User() const {
         return m_user;
      }
      void User(const UserPtr& user) {
         m_user = user;
      }
      [[nodiscard]] const DataBasePtr& DataBase() const {
         return m_dataBase;
      }
      void DataBase(const DataBasePtr& dataBase) {
         m_dataBase = dataBase;
      }

      [[nodiscard]] const std::string& UserName() const {
         return m_user->UserName();
      }
      void UserName(const std::string& userName) {
         m_user->UserName(userName);
      }
      [[nodiscard]] const std::string& PassWord() const {
         return m_user->PassWord();
      }
      void PassWord(const std::string& passWord) {
         m_user->PassWord(passWord);
      }
      [[nodiscard]] const std::string& FirstName() const {
         return m_user->FirstName();
      }
      void FirstName(const std::string& firstName) {
         m_user->FirstName(firstName);
      }
      [[nodiscard]] const std::string& LastName() const {
         return m_user->LastName();
      }
      void LastName(const std::string& lastName) {
         m_user->LastName(lastName);
      }
      [[nodiscard]] const std::string& Address() const {
         return m_user->Address();
      }
      void Address(const std::string& address) {
         m_user->Address(address);
      }
      [[nodiscard]] const std::string& PhoneNumber() const {
         return m_user->PhoneNumber();
      }
      void PhoneNumber(const std::string& phoneNumber) {
         m_user->PhoneNumber(phoneNumber);
      }
      [[nodiscard]] const std::string& UserType() const {
         return m_user->UserType();
      }
      void UserType(const std::string& userType) {
         m_user->UserType(userType);
      }
      [[nodiscard]] uint64_t RegisterTime() const {
         return m_user->RegisterTime();
      }
      void RegisterTime(uint64_t registerTime) {
         m_user->RegisterTime(registerTime);
      }

      [[nodiscard]] const std::string& DBAddress() const {
         return m_dataBase->HostAddress();
      }
      void DBAddress(const std::string& address) {
         m_dataBase->HostAddress(address);
      }
      [[nodiscard]] const std::string& DBUserName() const {
         return m_dataBase->UserName();
      }
      void DBUserName(const std::string& userName) {
         m_dataBase->UserName(userName);
      }
      [[nodiscard]] const std::string& DBPassword() const {
         return m_dataBase->PassWord();
      }
      void DBPassword(const std::string& password) {
         m_dataBase->Password(password);
      }
      [[nodiscard]] uint16_t DBPort() const {
         return m_dataBase->Port();
      }
      void DBPort(uint16_t port) {
         m_dataBase->Port(port);
      }
      [[nodiscard]] const std::string& DatabaseName() const {
         return m_dataBase->DatabaseName();
      }
      void DatabaseName(const std::string& databaseName) {
         m_dataBase->DatabaseName(databaseName);
      }

     private:
      UserPtr m_user{new model::User};
      DataBasePtr m_dataBase{new model::DataBase};
   };
}  // namespace anar::model
#endif  // ANAR_LOGIN_HPP
