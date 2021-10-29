#ifndef ANAR_USER_H
#define ANAR_USER_H

#include "anar/model/model.hpp"

namespace anar::model {
   namespace UserTypes {
      const std::string ADMIN = "admin";
      const std::string OPERATOR = "operator";
      const std::string EMPLOYER = "employer";
   }  // namespace UserTypes

   class User : virtual public Model {
     public:
      User()
          : Model("User", "User") {
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
   using UserPtr = std::shared_ptr<User>;
}  // namespace anar::model

#endif  // ANAR_USER_H
