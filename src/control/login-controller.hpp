#ifndef CONTROL_LOGIN_CONTROLLER_HPP
#define CONTROL_LOGIN_CONTROLLER_HPP

#include "base-controller.hpp"
#include <model/login.hpp>

namespace parspark::control {
   class LoginController;
   using LoginControllerPtr = std::shared_ptr<LoginController>;
   class LoginController : public BaseController {
    public:
      static LoginControllerPtr Create();
      explicit LoginController();

      bool DoLogin(const model::LoginPtr& login);
      bool SaveDataBaseSettings(const model::DataBasePtr& dataBase);
      model::DataBasePtr LoadLoginSeeting();
   };
} // namespace parspark::control

#endif // CONTROL_LOGIN_CONTROLLER_HPP
