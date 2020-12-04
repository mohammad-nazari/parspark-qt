import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/view/common"

Column{
   property var cameraSettings: ({})

   id: cameraId
   padding: 10
   spacing: 10
   GroupBox {
      id: activeEnterCameraGroupBoxId
      title: qsTr("Active Enter Camera")
      checkable: true
      checked: cameraSettings.enterAddress.enable
      onCheckedChanged: {cameraSettings.enterAddress.enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            labelText: qsTr("Address:")
            labelWidth: 100
            placeholderTextText:qsTr("Input enter camera address")
            textFieldWidth: 470
            textFieldText: cameraSettings.enterAddress.address
            onTextFieldTextChanged: {cameraSettings.enterAddress.address = textFieldText}
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
      checked: cameraSettings.exitAddress.enable
      onCheckedChanged: {cameraSettings.exitAddress.enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            id: exitCameraAddressTextFieldId
            labelText: qsTr("Address:")
            labelWidth: 100
            placeholderTextText:qsTr("Input exit camera address")
            textFieldWidth: 470
            textFieldText: cameraSettings.exitAddress.address
            onTextFieldTextChanged: {cameraSettings.exitAddress.address = textFieldText}
         }
         CommonButton{
            id: testExitCameraButtonId
            width: 100
            buttonText: qsTr("Test")
         }
      }
   }
}
