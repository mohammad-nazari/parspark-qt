import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.3
import "../common"

ApplicationWindow  {
    property var loginInfo: {
        userName: ""
        passWord: ""
        serverAddress: ""
        serverUser: ""
        serverPassword: ""
        serverPort: 1
        serverDBName: ""
        loginDone: false
        error: ""
    }
    MessageDialog {
        id: messageDialog
        icon: StandardIcon.Critical
    }
    function doLogin(){
        login.doLogin(loginInfo)
        if(login.loginInfo.loginDone){
            close();
        }else{
            messageDialog.text = login.loginInfo.error;
            messageDialog.title =  "Login failed";
            messageDialog.visible = true;
        }
    }
    Component.onCompleted: {
        login.loadLoginInfo();
        loginInfo = login.loginInfo;
        console.log(loginInfo.serverPort)
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
    Column{
        id: settingColumnId
        padding: 5
        spacing: 5
        CommonTextField {
            id: userTextFieldlId
            labelText: qsTr("User Name:")
            labelWidth: 100
            placeholderTextText:qsTr("Input user name")
            textFieldWidth: 200
            onTextFieldTextChanged: {loginInfo.userName = textFieldText}
        }
        CommonTextField {
            id: passwordTextFieldlId
            labelText: qsTr("Password:")
            labelWidth: 100
            placeholderTextText:qsTr("Input user password")
            textFieldWidth: 200
            textFieldEchoMode: TextInput.Password
            onTextFieldTextChanged: {loginInfo.passWord = textFieldText}
        }
        GroupBox {
            id: showDataBaseSettingId
            title: qsTr("Set Database Information")
            checkable: true
            checked: false
            Column{
                visible: showDataBaseSettingId.checked
                padding: 5
                spacing: 5
                CommonTextField {
                    id: serverAddressTextFieldlId
                    labelText: qsTr("Server Address:")
                    labelWidth: 100
                    placeholderTextText:qsTr("Input database server address")
                    textFieldWidth: 200
                    textFieldText: loginInfo.serverAddress
                    onTextFieldTextChanged: {loginInfo.serverAddress = textFieldText}
                }
                CommonTextField {
                    id: serverUserTextFieldlId
                    labelText: qsTr("User Name:")
                    labelWidth: 100
                    placeholderTextText:qsTr("Input database server user name")
                    textFieldWidth: 200
                    textFieldText: loginInfo.serverUser
                    onTextFieldTextChanged: {loginInfo.serverUser = textFieldText}
                }
                CommonTextField {
                    id: serverPasswordTextFieldlId
                    labelText: qsTr("Password:")
                    labelWidth: 100
                    placeholderTextText:qsTr("Input database server user password")
                    textFieldWidth: 200
                    textFieldEchoMode: TextInput.Password
                    textFieldText: loginInfo.serverPassword
                    onTextFieldTextChanged: {loginInfo.serverPassword = textFieldText}
                }
                CommonSpinBox {
                    id: serverPortSpinBoxId
                    labelText: qsTr("Port:")
                    labelWidth: 100
                    minimumValueValue: 1
                    maximumValueValue: 65535
                    spinBoxValue: loginInfo.serverPort
                    onSpinBoxValueChanged: {loginInfo.serverPort = spinBoxValue}
                }
                CommonTextField {
                    id: serverDBNameTextFieldlId
                    labelText: qsTr("Database Name:")
                    labelWidth: 100
                    placeholderTextText:qsTr("Input database name")
                    textFieldWidth: 200
                    textFieldText: loginInfo.serverDBName
                    onTextFieldTextChanged: {loginInfo.serverDBName = textFieldText}
                }
            }
        }
        RowLayout {
            width: 340
            CommonButton{
                id: loginButtonId
                buttonText: qsTr("Login")
                onClicked: doLogin()
            }
            CommonButton{
                id: exitButtonId
                buttonText: qsTr("Exit")
                onClicked: close()
            }
        }
    }
}
