import QtQuick
import QtQuick.Controls

Column {
   property string address: qsTr("127.0.0.1")
   property int port: 6290

   leftPadding: 5
   spacing: 2
   Column {
      leftPadding: 5
      spacing: 2
      CommonTextField {
         id: serverAddressTextFieldId
         labelText: qsTr("Server IP address:")
         labelWidth: 100
         placeholderTextText:qsTr("Input address")
         textFieldWidth: 200
         textFieldText: address
         onTextFieldTextChanged: {address = textFieldText}
      }
      CommonSpinBox {
         labelText: qsTr("Port number:")
         labelWidth: 100
         minimumValueValue: 1
         maximumValueValue: 65535
         spinBoxValue: port
         onSpinBoxValueChanged: {port = spinBoxValue}
      }
      CommonButton{
         id: testServerConnectionId
         width: 100
         buttonText: qsTr("Test")
      }
   }
}
