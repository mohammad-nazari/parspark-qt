import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column{
   padding: 10
   spacing: 10
   GroupBox {
      id: activeEnterCameraGroupBoxId
      title: qsTr("Active Enter Camera")
      checkable: true
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            labelText: qsTr("Address:")
            labelWidth: 100
            placeholderTextText:qsTr("Input enter camera address")
            textFieldWidth: 470
         }
         CommonButton{
            id: testEnterCameraButtonId
            width: 100
            buttonText: qsTr("Test")
         }
      }
   }
   GroupBox {
      id: activeExitCameraGroupBoxId
      title: qsTr("Active Exit Camera")
      checkable: true
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            id: exitCameraAddressTextFieldId
            labelText: qsTr("Address:")
            labelWidth: 100
            placeholderTextText:qsTr("Input exit camera address")
            textFieldWidth: 470
         }
         CommonButton{
            id: testExitCameraButtonId
            width: 100
            buttonText: qsTr("Test")
         }
      }
   }
}
