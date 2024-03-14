import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Column {
    property var cameraSettings: ({})

    id: cameraId
    padding: 10
    spacing: 10
    GroupBox {
        id: activeEnterCameraGroupBoxId
        label: CheckBox {
            id: activeEnterCamera
            text: qsTr("Active Enter Camera")
            checked: cameraSettings.EnterCamera.Enable
            onCheckedChanged: {cameraSettings.EnterCamera.Enable = checked}
        }
        Column {
            enabled: activeEnterCamera.checked
            padding: 5
            spacing: 5
            CommonTextField {
                id: enterCameraAddressTextFieldId
                labelText: qsTr("Address:")
                labelWidth: 100
                placeholderTextText: qsTr("Input enter camera address")
                textFieldWidth: 470
                textFieldText: cameraSettings.EnterCamera.Address
                onTextFieldTextChanged: {cameraSettings.EnterCamera.Address = textFieldText}
            }
            CommonButton {
                id: testEnterCameraButtonId
                width: 100
                buttonText: qsTr("Test")
            }
        }
    }
    GroupBox {
        id: activeExitCameraGroupBoxId
        label: CheckBox {
            id: activeExitCamera
            text: qsTr("Active Exit Camera")
            checked: cameraSettings.ExitCamera.Enable
            onCheckedChanged: {cameraSettings.ExitCamera.Enable = checked}
        }
        Column {
            enabled: activeExitCamera.checked
            padding: 5
            spacing: 5
            CommonTextField {
                id: exitCameraAddressTextFieldId
                labelText: qsTr("Address:")
                labelWidth: 100
                placeholderTextText: qsTr("Input exit camera address")
                textFieldWidth: 470
                textFieldText: cameraSettings.ExitCamera.Address
                onTextFieldTextChanged: {cameraSettings.ExitCamera.Address = textFieldText}
            }
            CommonButton {
                id: testExitCameraButtonId
                width: 100
                buttonText: qsTr("Test")
            }
        }
    }
}
