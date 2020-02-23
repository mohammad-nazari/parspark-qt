#include "login-view.hpp"
#include <control/settings-controller.hpp>
#include <src/control/login-controller.hpp>
#include <src/model/login.hpp>

namespace parspark::view {
   LoginViewPtr LoginView::Create() {
      return std::make_shared<LoginView>();
   }

   LoginView::LoginView(QObject* parent)
       : QObject(parent) {
   }

   void LoginView::doLogin(QVariantMap item) {
      m_loginInfo = item;
      qDebug() << item;
      model::LoginPtr login{new model::Login};
      login->User::UserName(m_loginInfo["userName"].toString());
      login->User::Password(m_loginInfo["passWord"].toString());
      login->DataBase::Address(m_loginInfo["serverAddress"].toString());
      login->DataBase::UserName(m_loginInfo["serverUser"].toString());
      login->DataBase::Password(m_loginInfo["serverPassword"].toString());
      login->Port(m_loginInfo["serverPort"].toInt());
      login->DatabaseName(m_loginInfo["serverDBName"].toString());
      control::LoginControllerPtr ctlLogin{new control::LoginController()};
      m_loginInfo["loginDone"] = ctlLogin->DoLogin(login);
      m_loginInfo["error"] = "Error: " + login->Error();
      if (m_loginInfo["loginDone"].toBool()) {
         model::DataBasePtr dataBase{new model::DataBase};
         dataBase->Address(m_loginInfo["serverAddress"].toString());
         dataBase->UserName(m_loginInfo["serverUser"].toString());
         dataBase->Password(m_loginInfo["serverPassword"].toString());
         dataBase->Port(m_loginInfo["serverPort"].toInt());
         dataBase->DatabaseName(m_loginInfo["serverDBName"].toString());
         control::SSettingsController::Instance()->DataBase(dataBase);
         control::SSettingsController::Instance()->Save();
      }
      emit loginInfoChanged();
   }

   void LoginView::loadLoginInfo() {
      auto dataBase = control::SSettingsController::Instance()->DataBase();
      m_loginInfo["userName"] = "";
      m_loginInfo["passWord"] = "";
      m_loginInfo["serverAddress"] = dataBase->Address();
      m_loginInfo["serverUser"] = dataBase->UserName();
      m_loginInfo["serverPassword"] = dataBase->Password();
      m_loginInfo["serverPort"] = dataBase->Port();
      m_loginInfo["serverDBName"] = dataBase->DatabaseName();
      emit loginInfoChanged();
   }
} // namespace parspark::view
