import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/app/pars-park-app/view/common"

Column{
   property var dataBaseSettings: ({})

   id: dataBaseId
   padding: 10
   spacing: 10
   CommonTextField {
      id: serverAddressTextFieldId
      labelText: qsTr("Server Address:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server address")
      textFieldWidth: 500
      textFieldText: dataBaseSettings.HostAddress
      onTextFieldTextChanged: {dataBaseSettings.HostAddress = textFieldText}
   }
   CommonTextField {
      id: serverUserTextFieldId
      labelText: qsTr("User Name:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server user name")
      textFieldWidth: 500
      textFieldText: dataBaseSettings.DBUserName
      onTextFieldTextChanged: {dataBaseSettings.DBUserName = textFieldText}
   }
   CommonTextField {
      id: serverPasswordTextFieldId
      labelText: qsTr("Password:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server user password")
      textFieldWidth: 500
      textFieldEchoMode: TextInput.Password
      textFieldText: dataBaseSettings.DBPassWord
      onTextFieldTextChanged: {dataBaseSettings.DBPassWord = textFieldText}
   }
   CommonSpinBox {
      id: serverPortSpinBoxId
      labelText: qsTr("Port:")
      labelWidth: 100
      minimumValueValue: 1
      maximumValueValue: 65535
      spinBoxValue: dataBaseSettings.Port
      onSpinBoxValueChanged: {dataBaseSettings.Port = spinBoxValue}
   }
   CommonTextField {
      id: serverDBNameTextFieldId
      labelText: qsTr("Database Name:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database name")
      textFieldWidth: 500
      textFieldText: dataBaseSettings.DatabaseName
      onTextFieldTextChanged: {dataBaseSettings.DatabaseName = textFieldText}
   }
   CommonButton{
      id: testDbButtonId
      width: 200
      buttonText: qsTr("Test DB connection")
   }
}
