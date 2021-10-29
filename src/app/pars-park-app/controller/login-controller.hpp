#ifndef ANAR_PARS_PARK_CONTROLLER_LOGIN_HPP
#define ANAR_PARS_PARK_CONTROLLER_LOGIN_HPP

#include "anar/controller/controller.hpp"
#include "model/login.hpp"

namespace anar::controller {
   class LoginController;
   using LoginControllerPtr = std::shared_ptr<LoginController>;
   class LoginController : public Controller {
     public:
      static LoginControllerPtr Create();
      explicit LoginController();

      bool DoLogin(const model::LoginPtr& login);
      bool SaveDataBaseSettings(const model::DataBaseModelPtr& dataBase);
      model::DataBaseModelPtr LoadLoginSetting();
   };
}  // namespace anar::controller

#endif  // ANAR_PARS_PARK_CONTROLLER_LOGIN_HPP
