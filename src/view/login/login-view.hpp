#ifndef VIEW_LOGIN_VIEW_HPP
#define VIEW_LOGIN_VIEW_HPP

#include <QJSEngine>
#include <QQmlEngine>
#include <QVariantMap>
#include <control/login-controller.hpp>
#include <model/user.hpp>
#include <view/base-view.hpp>

namespace parspark::view {
   class LoginView;
   using LoginViewPtr = std::shared_ptr<LoginView>;
   class LoginView : public BaseView {
      Q_OBJECT
      Q_PROPERTY(
          QVariantMap loginInfo MEMBER m_loginInfo NOTIFY loginInfoChanged)

    public:
      static LoginViewPtr Create();
      explicit LoginView(QObject* parent = nullptr);
      static LoginView* LoginViewObjectProvider(QQmlEngine* engine,
                                              QJSEngine* scriptEngine);

      QVariantMap loginInfo() const {
         return m_loginInfo;
      }
      void setLoginInfo(QVariantMap loginInfo) {
         m_loginInfo = loginInfo;
      }
     Q_INVOKABLE bool IsLoggedin() {
         return m_done;
      }

    signals:
      void loginInfoChanged(QVariantMap loginInfo);

    public slots:
      void loadLoginInfo();
      void doLogin(QVariantMap loginInfo);

    private:
      QVariantMap m_loginInfo;
      control::LoginControllerPtr m_loginController{
          new control::LoginController};
   };
} // namespace parspark::view
#endif // VIEW_LOGIN_VIEW_HPP
