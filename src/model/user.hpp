#ifndef ANAR_USER_H
#define ANAR_USER_H

#include "model.hpp"

namespace anar::model {
   namespace UserTypes {
      const std::string ADMIN = "admin";
      const std::string OPERATOR = "operator";
      const std::string EMPLOYER = "employer";
   }  // namespace UserTypes

   class User;
   using UserPtr = std::shared_ptr<User>;
   class User : public Model {
     public:
      static UserPtr Create();
      User();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const std::string& UserName() const {
         return m_userName;
      }
      void UserName(const std::string& userName) {
         m_userName = userName;
      }
      [[nodiscard]] const std::string& PassWord() const {
         return m_passWord;
      }
      void PassWord(const std::string& passWord) {
         m_passWord = passWord;
      }
      [[nodiscard]] const std::string& FirstName() const {
         return m_firstName;
      }
      void FirstName(const std::string& firstName) {
         m_firstName = firstName;
      }
      [[nodiscard]] const std::string& LastName() const {
         return m_lastName;
      }
      void LastName(const std::string& lastName) {
         m_lastName = lastName;
      }
      [[nodiscard]] const std::string& Address() const {
         return m_address;
      }
      void Address(const std::string& address) {
         m_address = address;
      }
      [[nodiscard]] const std::string& PhoneNumber() const {
         return m_phoneNumber;
      }
      void PhoneNumber(const std::string& phoneNumber) {
         m_phoneNumber = phoneNumber;
      }
      [[nodiscard]] const std::string& UserType() const {
         return m_userType;
      }
      void UserType(const std::string& userType) {
         m_userType = userType;
      }
      [[nodiscard]] uint64_t RegisterTime() const {
         return m_registerTime;
      }
      void RegisterTime(uint64_t registerTime) {
         m_registerTime = registerTime;
      }

     protected:
      std::string m_userName{"admin"};
      std::string m_passWord{"admin"};
      std::string m_firstName{"admin"};
      std::string m_lastName{"admin"};
      std::string m_address;
      std::string m_phoneNumber;
      std::string m_userType{UserTypes::EMPLOYER};
      uint64_t m_registerTime{0};
   };
}  // namespace anar::model

#endif  // ANAR_USER_H
