#ifndef MODEL_LOGIN_HPP
#define MODEL_LOGIN_HPP

#include "settings/database.hpp"
#include "user.hpp"

namespace parspark::model {
   class Login;
   using LoginPtr = std::shared_ptr<Login>;
   class Login : public User, public DataBase {
    public:
      static LoginPtr Create();
      Login();
   };
} // namespace parspark::model
#endif // MODEL_LOGIN_HPP
