#ifndef VIEW_LOGIN_HPP
#define VIEW_LOGIN_HPP

#include <QDebug>
#include <QObject>
#include <src/model/user.hpp>

namespace parspark::view {
   class LoginView;
   using LoginViewPtr = std::shared_ptr<LoginView>;
   class LoginView : public QObject {
      Q_OBJECT
      Q_PROPERTY(QVariantMap loginInfo MEMBER m_loginInfo NOTIFY loginInfoChanged)

    public:
      static LoginViewPtr Create();
      explicit LoginView(QObject* parent = nullptr);
      QVariantMap loginInfo() const {
         return m_loginInfo;
      }
      void setLoginInfo(QVariantMap loginInfo) {
         m_loginInfo = loginInfo;
      }
      bool IsLoggedin() {
         return m_loginInfo["loginDone"].toBool();
      }

    signals:
      void loginDone();
      void loginInfoChanged();

    public slots:
      void doLogin(QVariantMap item);
      void loadLoginInfo();

    private:
      QVariantMap m_loginInfo;
   };
} // namespace parspark::view
#endif // VIEW_LOGIN_HPP
