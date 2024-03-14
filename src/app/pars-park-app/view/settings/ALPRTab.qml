import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Column {
    property var alprSettings: ({})

    id: alprId
    padding: 10
    spacing: 2
    GroupBox {
        id: savePlateNumberGroupBoxId
        label: CheckBox {
            id: savePlateNumberId
            text: qsTr("Save Plate Number")
            checked: alprSettings.Enable
            onCheckedChanged: {alprSettings.Enable = checked}
        }
        Column {
            enabled: savePlateNumberId.checked
            leftPadding: 5
            spacing: 10
            ButtonGroup {
                id: alprOptions
            }
            Column {
                spacing: 2
                RadioButton {
                    id: submitWithCameraId
                    text: qsTr("Submit with camera")
                    checked: alprSettings.ByCamera.Enable
                    onCheckedChanged: {alprSettings.ByCamera.Enable = checked}
                    ButtonGroup.group: alprOptions
                }
                Column {
                    enabled: submitWithCameraId.checked
                    leftPadding: 5
                    spacing: 2
                    CheckBox {
                        id: allowSaveWithoutEnterCheckBoxId
                        text: qsTr("Allow save without enter plate number")
                        checked: alprSettings.ByCamera.SubmitWithoutEnterPlate
                        onCheckedChanged: {alprSettings.ByCamera.SubmitWithoutEnterPlate = checked}
                    }
                    CheckBox {
                        id: allowSaveWithoutExitCheckBoxId
                        text: qsTr("Allow save without exit plate number")
                        checked: alprSettings.ByCamera.SubmitWithoutExitPlate
                        onCheckedChanged: {alprSettings.ByCamera.SubmitWithoutExitPlate = checked}
                    }
                }
            }
            RadioButton {
                id: submitManuallyRadioButtonId
                text: qsTr("Submit manually")
                ButtonGroup.group: alprOptions
                checked: !alprSettings.ByCamera.Enable
                onCheckedChanged: {alprSettings.ByCamera.Enable = !checked}
            }
        }
    }
}
