#include "login-view.hpp"

#include <QDebug>

#include "controller/settings-controller.hpp"

namespace anar::view {
   LoginViewPtr LoginView::Create() {
      return std::make_shared<LoginView>();
   }
   LoginView::LoginView(QObject* parent)
       : View(parent) {
   }
   LoginView* LoginView::LoginViewObjectProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)

      return new LoginView;
   }

   void LoginView::loadLoginInfo() {
      auto dataBase = m_loginController->LoadLoginSetting();
      m_loginInfo["userName"] = "";
      m_loginInfo["passWord"] = "";
      m_loginInfo["serverAddress"] = dataBase->HostAddress().c_str();
      m_loginInfo["serverUser"] = dataBase->UserName().c_str();
      m_loginInfo["serverPassword"] = dataBase->PassWord().c_str();
      m_loginInfo["serverPort"] = dataBase->Port();
      m_loginInfo["serverDBName"] = dataBase->DatabaseName().c_str();
   }
   void LoginView::doLogin(QVariantMap loginInfo) {
      m_loginInfo = loginInfo;
      model::LoginPtr login{new model::Login};
      login->User().UserName(m_loginInfo["userName"].toString().toStdString());
//      login->PassWord(m_loginInfo["passWord"].toString().toStdString());
//      login->DBAddress(m_loginInfo["serverAddress"].toString().toStdString());
//      login->DBUserName(m_loginInfo["serverUser"].toString().toStdString());
//      login->DBPassword(m_loginInfo["serverPassword"].toString().toStdString());
//      login->DBPort(m_loginInfo["serverPort"].toInt());
//      login->DatabaseName(m_loginInfo["serverDBName"].toString().toStdString());
      m_done = m_loginController->DoLogin(login);
      m_error = std::string("Error: " + m_loginController->Error()).c_str();
      // Save new database setting if done successfully
      if (!m_done) {
         return;
      }
      m_error.clear();
      model::DataBasePtr dataBase{new model::DataBase};
      dataBase->HostAddress(m_loginInfo["serverAddress"].toString().toStdString());
      dataBase->UserName(m_loginInfo["serverUser"].toString().toStdString());
      dataBase->Password(m_loginInfo["serverPassword"].toString().toStdString());
      dataBase->Port(m_loginInfo["serverPort"].toInt());
      dataBase->DatabaseName(m_loginInfo["serverDBName"].toString().toStdString());
      if (!m_loginController->SaveDataBaseSettings(dataBase)) {
         m_error.fromStdString("Error: " + m_loginController->Error());
      }
   }
}  // namespace anar::view
