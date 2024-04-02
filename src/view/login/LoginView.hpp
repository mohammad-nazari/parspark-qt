#ifndef ANAR_PARS_PARK_VIEW_LOGIN_HPP
#define ANAR_PARS_PARK_VIEW_LOGIN_HPP

#include <QVariantMap>
#include <utility>

#include "controller/login-controller.hpp"
#include "model/database/user-model.hpp"
#include "view/View.hpp"

namespace anar::parspark::view {
    class LoginView;
    using LoginViewPtr = std::shared_ptr<LoginView>;
    class LoginView : public View {
        Q_OBJECT
        QML_ELEMENT
        QML_SINGLETON
        QML_NAMED_ELEMENT(LoginApi)
        Q_DISABLE_COPY(LoginView)
        Q_PROPERTY(QVariantMap loginInfo MEMBER m_loginInfo NOTIFY loginInfoChanged)
        Q_PROPERTY(bool isLoggedIn MEMBER m_isLoggedIn NOTIFY isLoggedIn)
       public:
        static LoginView* create(QQmlEngine* engine, QJSEngine* scriptEngine);
        static LoginView* Instance();

        [[nodiscard]] QVariantMap loginInfo() const {
            return m_loginInfo;
        }
        void setLoginInfo(QVariantMap loginInfo) {
            m_loginInfo = std::move(loginInfo);
        }

        [[nodiscard]] bool IsLoggedIn() const {
            return m_isLoggedIn;
        }

       signals:
        void loginInfoChanged(QVariantMap loginInfo);
        void isLoggedIn();

       public slots:
        void loadLoginInfo();
        void doLogin(QVariantMap loginInfo);

       private:
        static LoginView* m_instance;

        explicit LoginView(QObject* parent = nullptr);

        QVariantMap m_loginInfo;
        controller::LoginControllerPtr m_loginController{new controller::LoginController};
        bool m_isLoggedIn{false};
    };
}  // namespace anar::parspark::view
#endif  // ANAR_PARS_PARK_VIEW_LOGIN_HPP
