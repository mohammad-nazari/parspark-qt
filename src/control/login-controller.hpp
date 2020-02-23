#ifndef LOGIN_CONTROLLER_HPP
#define LOGIN_CONTROLLER_HPP

#include <QObject>
#include <model/login.hpp>

namespace parspark::control {
   class LoginController;
   using LoginControllerPtr = std::shared_ptr<LoginController>;
   class LoginController : public QObject {
      Q_OBJECT
    public:
      static LoginControllerPtr Create();
      explicit LoginController(QObject* parent = nullptr);

      bool DoLogin(model::LoginPtr& login);
    signals:
   };
} // namespace parspark::control

#endif // LOGIN_CONTROLLER_HPP
