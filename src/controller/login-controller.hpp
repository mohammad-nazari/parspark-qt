#ifndef ANAR_LOGIN_CONTROLLER_HPP
#define ANAR_LOGIN_CONTROLLER_HPP

#include "base-controller.hpp"
#include "model/login.hpp"

namespace anar::controller {
   class LoginController;
   using LoginControllerPtr = std::shared_ptr<LoginController>;
   class LoginController : public BaseController {
     public:
      static LoginControllerPtr Create();
      explicit LoginController();

      bool DoLogin(const model::LoginPtr& login);
      bool SaveDataBaseSettings(const model::DataBasePtr& dataBase);
      model::DataBasePtr LoadLoginSetting();
   };
}  // namespace anar::controller

#endif  // ANAR_LOGIN_CONTROLLER_HPP
