import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column{
   property var dataBaseSettings: ({})

   id: dataBaseId
   padding: 10
   spacing: 10
   CommonTextField {
      id: serverAddressTextFieldlId
      labelText: qsTr("Server Address:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server address")
      textFieldWidth: 500
      textFieldText: dataBaseSettings.address
      onTextFieldTextChanged: {dataBaseSettings.address = textFieldText}
   }
   CommonTextField {
      id: serverUserTextFieldlId
      labelText: qsTr("User Name:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server user name")
      textFieldWidth: 500
      textFieldText: dataBaseSettings.userName
      onTextFieldTextChanged: {dataBaseSettings.userName = textFieldText}
   }
   CommonTextField {
      id: serverPasswordTextFieldlId
      labelText: qsTr("Password:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server user password")
      textFieldWidth: 500
      textFieldEchoMode: TextInput.Password
      textFieldText: dataBaseSettings.password
      onTextFieldTextChanged: {dataBaseSettings.password = textFieldText}
   }
   CommonSpinBox {
      id: serverPortSpinBoxId
      labelText: qsTr("Port:")
      labelWidth: 100
      minimumValueValue: 1
      maximumValueValue: 65535
      spinBoxValue: dataBaseSettings.port
      onSpinBoxValueChanged: {dataBaseSettings.port = spinBoxValue}
   }
   CommonTextField {
      id: serverDBNameTextFieldlId
      labelText: qsTr("Database Name:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database name")
      textFieldWidth: 500
      textFieldText: dataBaseSettings.databaseName
      onTextFieldTextChanged: {dataBaseSettings.databaseName = textFieldText}
   }
   CommonButton{
      id: testDbButtonId
      width: 200
      buttonText: qsTr("Test DB connection")
   }
}
