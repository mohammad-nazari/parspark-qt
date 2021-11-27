#ifndef ANAR_PARS_PARK_CONTROLLER_LOGIN_HPP
#define ANAR_PARS_PARK_CONTROLLER_LOGIN_HPP

#include "anar/controller.hpp"
#include "anar/database-model.hpp"
#include "model/login-model.hpp"

namespace anar::parspark::controller {
   class LoginController;
   using LoginControllerPtr = std::shared_ptr<LoginController>;
   class LoginController : public anar::controller::Controller {
     public:
      static LoginControllerPtr Create();
      explicit LoginController();

      bool DoLogin(const model::LoginModel& login);
      bool SaveDataBaseSettings(const anar::model::DataBaseModel& dataBase);
      anar::model::DataBaseModel LoadLoginSetting();
   };
}  // namespace anar::parspark::controller

#endif  // ANAR_PARS_PARK_CONTROLLER_LOGIN_HPP
