import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

ApplicationWindow {
    property var loginInfo: {
       LoginApi.loadLoginInfo();
       return LoginApi.loginInfo;
    }
    MessageDialog {
       id: messageDialog
       // icon: StandardIcon.Critical
    }
    function doLogin(){
       LoginApi.doLogin(loginInfo)
       if(LoginApi.isLoggedIn){
          // Any error in save database settings in file
          if(LoginApi.error.length > 0){
             messageDialog.text = LoginApi.error;
             messageDialog.title =  qsTr("Error on save database settings");
             messageDialog.visible = true;
             messageDialog.icon = StandardIcon.Warning
          }
          close();
       }else{
          messageDialog.text = LoginApi.error;
          messageDialog.title =  qsTr("Login failed");
          messageDialog.visible = true;
       }
    }

    id: settingWindowId
    visible: true
    width: 350
    height: 300
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: qsTr("Login")
    modality: Qt.WindowModal
    flags: Qt.Dialog
    Column {
        id: settingColumnId
        padding: 5
        spacing: 5
        CommonTextField {
            id: userTextFieldId
            labelText: qsTr("User Name:")
            textFieldText: qsTr("admin11")
            labelWidth: 100
            placeholderTextText: qsTr("Input user name")
            textFieldWidth: 200
            focus: true
            onTextFieldTextChanged: {settingWindowId.loginInfo.userName = textFieldText}
        }
        CommonTextField {
            id: passwordTextFieldId
            labelText: qsTr("Password:")
            textFieldText: qsTr("admin11")
            labelWidth: 100
            placeholderTextText: qsTr("Input user password")
            textFieldWidth: 200
            textFieldEchoMode: TextInput.Password
            onTextFieldTextChanged: {settingWindowId.loginInfo.passWord = textFieldText}
        }
        GroupBox {
            id: dataBaseSettingId
            label: CheckBox {
                id: showDataBaseSettingId
                checked: false
                text: qsTr("Set Database Information")
            }
            Column{
               visible: showDataBaseSettingId.checked
               padding: 5
               spacing: 5
               CommonTextField {
                  id: serverAddressTextFieldId
                  labelText: qsTr("Server Address:")
                  labelWidth: 100
                  placeholderTextText:qsTr("Input database server address")
                  textFieldWidth: 200
                  textFieldText: settingWindowId.loginInfo.serverAddress
                  onTextFieldTextChanged: {settingWindowId.loginInfo.serverAddress = textFieldText}
               }
               CommonTextField {
                  id: serverUserTextFieldId
                  labelText: qsTr("User Name:")
                  labelWidth: 100
                  placeholderTextText:qsTr("Input database server user name")
                  textFieldWidth: 200
                  textFieldText: settingWindowId.loginInfo.serverUser
                  onTextFieldTextChanged: {settingWindowId.loginInfo.serverUser = textFieldText}
               }
               CommonTextField {
                  id: serverPasswordTextFieldId
                  labelText: qsTr("Password:")
                  labelWidth: 100
                  placeholderTextText:qsTr("Input database server user password")
                  textFieldWidth: 200
                  textFieldEchoMode: TextInput.Password
                  textFieldText: settingWindowId.loginInfo.serverPassword
                  onTextFieldTextChanged: {settingWindowId.loginInfo.serverPassword = textFieldText}
               }
               CommonSpinBox {
                  id: serverPortSpinBoxId
                  labelText: qsTr("Port:")
                  labelWidth: 100
                  minimumValueValue: 1
                  maximumValueValue: 65535
                  spinBoxValue: settingWindowId.loginInfo.serverPort
                  onSpinBoxValueChanged: {settingWindowId.loginInfo.serverPort = spinBoxValue}
               }
               CommonTextField {
                  id: serverDBNameTextFieldId
                  labelText: qsTr("Database Name:")
                  labelWidth: 100
                  placeholderTextText:qsTr("Input database name")
                  textFieldWidth: 200
                  textFieldText: settingWindowId.loginInfo.serverDBName
                  onTextFieldTextChanged: {settingWindowId.loginInfo.serverDBName = textFieldText}
               }
            }
        }
        RowLayout {
            width: settingWindowId.width - 10
            CommonButton {
                id: loginButtonId
                buttonText: qsTr("Login")
                onClicked: doLogin()
            }
            CommonButton {
                id: exitButtonId
                buttonText: qsTr("Exit")
                activeFocusOnTab: true
                onClicked: close()
            }
        }
    }
}
