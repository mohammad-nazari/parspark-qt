#include "login.hpp"

namespace parspark::model {
   LoginPtr Login::Create() {
      return std::make_shared<Login>();
   }
   Login::Login() {
      BaseModel("Login");
   }
} // namespace parspark::model
