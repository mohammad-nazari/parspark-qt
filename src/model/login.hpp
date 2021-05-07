#ifndef ANAR_LOGIN_HPP
#define ANAR_LOGIN_HPP

#include "settings/database.hpp"
#include "user.hpp"

namespace anar::model {
   class Login;
   using LoginPtr = std::shared_ptr<Login>;
   class Login : public Model {
     public:
      static LoginPtr Create();
      Login();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] model::User& User() {
         return m_user;
      }
      void User(const model::User& user) {
         m_user = user;
      }
      [[nodiscard]] model::DataBase& DataBase() {
         return m_dataBase;
      }
      void DataBase(const model::DataBase& dataBase) {
         m_dataBase = dataBase;
      }

     private:
      model::User m_user;
      model::DataBase m_dataBase;
   };
}  // namespace anar::model
#endif  // ANAR_LOGIN_HPP
