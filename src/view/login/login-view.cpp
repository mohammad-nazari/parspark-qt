#include "login-view.hpp"
#include <control/login-controller.hpp>
#include <control/settings-controller.hpp>
#include <model/login.hpp>

namespace parspark::view {
   LoginViewPtr LoginView::Create() {
      return std::make_shared<LoginView>();
   }
   LoginView::LoginView(QObject* parent)
       : BaseView(parent) {
   }
   LoginView* LoginView::LoginViewObjectProvider(QQmlEngine* engine,
                                               QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)

      return new LoginView;
   }

   void LoginView::loadLoginInfo() {
      auto dataBase = m_loginController->LoadLoginSeeting();
      m_loginInfo["userName"] = "";
      m_loginInfo["passWord"] = "";
      m_loginInfo["serverAddress"] = dataBase->Address();
      m_loginInfo["serverUser"] = dataBase->UserName();
      m_loginInfo["serverPassword"] = dataBase->Password();
      m_loginInfo["serverPort"] = dataBase->Port();
      m_loginInfo["serverDBName"] = dataBase->DatabaseName();
   }
   void LoginView::doLogin(QVariantMap loginInfo) {
      m_loginInfo = loginInfo;
      model::LoginPtr login{new model::Login};
      login->User::UserName(m_loginInfo["userName"].toString());
      login->User::Password(m_loginInfo["passWord"].toString());
      login->DataBase::Address(m_loginInfo["serverAddress"].toString());
      login->DataBase::UserName(m_loginInfo["serverUser"].toString());
      login->DataBase::Password(m_loginInfo["serverPassword"].toString());
      login->Port(m_loginInfo["serverPort"].toInt());
      login->DatabaseName(m_loginInfo["serverDBName"].toString());
      m_done = m_loginController->DoLogin(login);
      m_error = "Error: " + m_loginController->Error();
      // Save new database setting if done successfully
      if (!m_done) {
         return;
      }
      m_error.clear();
      model::DataBasePtr dataBase{new model::DataBase};
      dataBase->Address(m_loginInfo["serverAddress"].toString());
      dataBase->UserName(m_loginInfo["serverUser"].toString());
      dataBase->Password(m_loginInfo["serverPassword"].toString());
      dataBase->Port(m_loginInfo["serverPort"].toInt());
      dataBase->DatabaseName(m_loginInfo["serverDBName"].toString());
      if (!m_loginController->SaveDataBaseSettings(dataBase)) {
         m_error = "Error: " + m_loginController->Error();
      }
   }
} // namespace parspark::view
