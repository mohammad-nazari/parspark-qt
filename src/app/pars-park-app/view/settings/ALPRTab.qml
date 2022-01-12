import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/app/pars-park-app/view/common"

Column{
    property var alprSettings: ({})

    id: alprId
    padding: 10
    spacing: 2
    GroupBox {
        id: savePlateNumberGroupBoxId
        title: qsTr("Save Plate Number")
        checkable: true
        checked: alprSettings.Enable
        onCheckedChanged: {alprSettings.Enable = checked}
        Column {
            leftPadding: 5
            spacing: 10
            ExclusiveGroup {
                id: alprOptions
            }
            Column {
                spacing: 2
                RadioButton {
                    id: submitWithCameraId
                    text: qsTr("Submit with camera")
                    checked: alprSettings.ByCamera.Enable
                    onCheckedChanged: {alprSettings.ByCamera.Enable = checked}
                    exclusiveGroup: alprOptions
                }
                Column{
                    enabled: submitWithCameraId.checked
                    leftPadding: 5
                    spacing: 2
                    CheckBox{
                        id: allowSaveWithoutEnterCheckBoxId
                        text: qsTr("Allow save without enter plate number")
                        checked: alprSettings.ByCamera.SubmitWithoutEnterPlate
                        onCheckedChanged: {alprSettings.ByCamera.SubmitWithoutEnterPlate = checked}
                    }
                    CheckBox{
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
                exclusiveGroup: alprOptions
                checked: !alprSettings.ByCamera.Enable
                onCheckedChanged: {alprSettings.ByCamera.Enable = !checked}
            }
        }
    }
}
