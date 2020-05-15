#ifndef MODEL_USER_H
#define MODEL_USER_H

#include "base-model.hpp"

namespace parspark::model {
   namespace UserTypes {
      const QString ADMIN = "admin";
      const QString OPERATOR = "operator";
      const QString EMPLOEE = "emploee";
   } // namespace UserTypes

   class User;
   using UserPtr = std::shared_ptr<User>;
   class User : public BaseModel {
    public:
       static UserPtr Create();
      User();

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
      QString FirstName() const {
         return m_firstName;
      }
      void FirstName(const QString& firstName) {
         m_firstName = firstName;
      }
      QString LastName() const {
         return m_lastName;
      }
      void LastName(const QString& lastName) {
         m_lastName = lastName;
      }
      QString Address() const {
         return m_address;
      }
      void Address(const QString& address) {
         m_address = address;
      }
      QString PhoneNumber() const {
         return m_phoneNumber;
      }
      void PhoneNumber(const QString& phoneNumber) {
         m_phoneNumber = phoneNumber;
      }
      QString UserType() const {
         return m_userType;
      }
      void UserType(const QString& userType) {
         m_userType = userType;
      }
      uint64_t RegisterTime() const {
         return m_registerTime;
      }
      void RegisterTime(const uint64_t& registerTime) {
         m_registerTime = registerTime;
      }

    protected:
      QString m_userName{"admin"};
      QString m_password{"admin"};
      QString m_firstName{"admin"};
      QString m_lastName{"admin"};
      QString m_address;
      QString m_phoneNumber;
      QString m_userType{UserTypes::EMPLOEE};
      uint64_t m_registerTime{0};

      // Jsonable interface
   public:
      bool FromJson(const QVariantMap &json) override;
      const QVariantMap ToJson() const override;
   };
} // namespace parspark::model

#endif // MODEL_USER_H
