#include "login-view.hpp"

#include "controller/settings-controller.hpp"

namespace anar::parspark::view {
   LoginView* LoginView::m_instance = nullptr;
   LoginView* LoginView::QmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine) {
      Q_UNUSED(engine)
      Q_UNUSED(scriptEngine)
      if (!m_instance) {
         m_instance = new LoginView();
      }
      return m_instance;
   }
   LoginView::LoginView(QObject* parent)
       : View(parent) {
   }

   void LoginView::loadLoginInfo() {
      auto dataBase = m_loginController->LoadLoginSetting();
      m_loginInfo["userName"] = "";
      m_loginInfo["passWord"] = "";
      m_loginInfo["serverAddress"] = dataBase.HostAddress.c_str();
      m_loginInfo["serverUser"] = dataBase.DBUserName.c_str();
      m_loginInfo["serverPassword"] = dataBase.DBPassWord.c_str();
      m_loginInfo["serverPort"] = dataBase.Port;
      m_loginInfo["serverDBName"] = dataBase.DatabaseName.c_str();
   }
   void LoginView::doLogin(QVariantMap loginInfo) {
      m_loginInfo = loginInfo;
      model::LoginModel login;
      login.UserName = (m_loginInfo["userName"].toString().toStdString());
      login.PassWord = (m_loginInfo["passWord"].toString().toStdString());
      login.HostAddress = (m_loginInfo["serverAddress"].toString().toStdString());
      login.DBUserName = (m_loginInfo["serverUser"].toString().toStdString());
      login.DBPassWord = (m_loginInfo["serverPassword"].toString().toStdString());
      login.Port = (m_loginInfo["serverPort"].toInt());
      login.DatabaseName = (m_loginInfo["serverDBName"].toString().toStdString());
      m_isLoggedIn = m_loginController->DoLogin(login);
      //      m_error = std::string("Error: " + m_loginController->Error()).c_str();
      // Save new database setting if done successfully
      if (!m_isLoggedIn) {
         return;
      }
      m_error.clear();
      anar::model::DataBaseModel dataBase;
      dataBase.HostAddress = (m_loginInfo["serverAddress"].toString().toStdString());
      dataBase.DBUserName = (m_loginInfo["serverUser"].toString().toStdString());
      dataBase.DBPassWord = (m_loginInfo["serverPassword"].toString().toStdString());
      dataBase.Port = (m_loginInfo["serverPort"].toInt());
      dataBase.DatabaseName = (m_loginInfo["serverDBName"].toString().toStdString());
      if (!m_loginController->SaveDataBaseSettings(dataBase)) {
         //         m_error.fromStdString("Error: " + m_loginController->Error());
      }
   }
}  // namespace anar::parspark::view
