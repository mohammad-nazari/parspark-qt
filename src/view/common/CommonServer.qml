import QtQuick 2.13
import QtQuick.Controls 1.4

Column {
   property string address: ""
   property int port: 50001

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
      }
      CommonSpinBox {
         labelText: qsTr("Port number:")
         labelWidth: 100
         minimumValueValue: 1
         maximumValueValue: 65535
         spinBoxValue: port
      }
      CommonButton{
         id: testServerConnectionId
         width: 100
         buttonText: qsTr("Test")
      }
   }
}
