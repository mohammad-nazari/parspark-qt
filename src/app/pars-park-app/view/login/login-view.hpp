#ifndef ANAR_PARS_PARK_VIEW_LOGIN_HPP
#define ANAR_PARS_PARK_VIEW_LOGIN_HPP

#include <QVariantMap>

#include "controller/login-controller.hpp"
#include "model/database/user-model.hpp"
#include "view/view.hpp"

namespace anar::parspark::view {
   class LoginView;
   using LoginViewPtr = std::shared_ptr<LoginView>;
   class LoginView : public View {
      Q_OBJECT
      Q_DISABLE_COPY(LoginView)
      Q_PROPERTY(QVariantMap loginInfo MEMBER m_loginInfo NOTIFY loginInfoChanged)

     public:
      static LoginView* QmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine);
      static LoginView* Instance();

      QVariantMap loginInfo() const {
         return m_loginInfo;
      }
      void setLoginInfo(QVariantMap loginInfo) {
         m_loginInfo = loginInfo;
      }

      bool IsLoggedIn() const {
         return m_isLoggedIn;
      }

     signals:
      void loginInfoChanged(QVariantMap loginInfo);

     public slots:
      void loadLoginInfo();
      void doLogin(QVariantMap loginInfo);

     private:
      static LoginView* m_instance;

      LoginView(QObject* parent = nullptr);

      QVariantMap m_loginInfo;
      controller::LoginControllerPtr m_loginController{new controller::LoginController};
      bool m_isLoggedIn{false};
   };
}  // namespace anar::parspark::view
#endif  // ANAR_PARS_PARK_VIEW_LOGIN_HPP
