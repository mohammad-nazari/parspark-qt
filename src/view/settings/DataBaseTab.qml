import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column{
   padding: 10
   spacing: 10
   CommonTextField {
      id: serverAddressTextFieldlId
      labelText: qsTr("Server Address:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server address")
      textFieldWidth: 500
   }
   CommonTextField {
      id: serverUserTextFieldlId
      labelText: qsTr("User Name:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server user name")
      textFieldWidth: 500
   }
   CommonTextField {
      id: serverPasswordTextFieldlId
      labelText: qsTr("Password:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database server user password")
      textFieldWidth: 500
      textFieldEchoMode: TextInput.Password
   }
   CommonSpinBox {
      id: serverPortSpinBoxId
      labelText: qsTr("Port:")
      labelWidth: 100
      minimumValueValue: 1
      maximumValueValue: 65535
      spinBoxValue: 3306
   }
   CommonTextField {
      id: serverDBNameTextFieldlId
      labelText: qsTr("Database Name:")
      labelWidth: 100
      placeholderTextText:qsTr("Input database name")
      textFieldWidth: 500
   }
   CommonButton{
      id: testDbButtonId
      width: 200
      buttonText: qsTr("Test DB connection")
   }
}
