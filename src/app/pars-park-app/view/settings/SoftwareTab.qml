import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Row {
    property var softwareSettings: ({})

    id: softwareId
    padding: 10
    spacing: 2
    GroupBox {
        title: qsTr("Active Sections")
        Column {
            leftPadding: 5
            spacing: 5
            CheckBox {
                id: activeEnterSectionCheckBoxId
                text: qsTr("Active enter section")
                checked: softwareSettings.ActiveEnter
                onCheckedChanged: {softwareSettings.ActiveEnter = checked}
            }
            CheckBox {
                id: activeExitSectionCheckBoxId
                text: qsTr("Active exit section")
                checked: softwareSettings.ActiveExit
                onCheckedChanged: {softwareSettings.ActiveExit = checked}
            }
        }
    }
    GroupBox {
        title: qsTr("Software Type")
        Column {
            leftPadding: 5
            spacing: 10
            ButtonGroup {
                id: softwareTypeOptions
            }
            Column {
                leftPadding: 5
                spacing: 2
                RadioButton {
                    id: serverSoftwareTypeRadioButtonId
                    text: qsTr("Server type")
                    ButtonGroup.group: softwareTypeOptions
                    checked: softwareSettings.IsServer
                    onCheckedChanged: {softwareSettings.IsServer = checked}
                }
                CommonSpinBox {
                    id: portNumberSpinBoxId
                    enabled: serverSoftwareTypeRadioButtonId.checked
                    labelText: qsTr("Port number:")
                    labelWidth: 100
                    minimumValueValue: 1
                    maximumValueValue: 65535
                    spinBoxValue: softwareSettings.Port
                    onSpinBoxValueChanged: {softwareSettings.Port = spinBoxValue}
                }
            }
            Column {
                leftPadding: 5
                spacing: 2
                RadioButton {
                    id: clientSoftwareTypeRadioButtonId
                    text: qsTr("Client type")
                    ButtonGroup.group: softwareTypeOptions
                    checked: !softwareSettings.IsServer
                    onCheckedChanged: {softwareSettings.IsServer = !checked}
                }
                CommonServer {
                    id: serverId
                    enabled: clientSoftwareTypeRadioButtonId.checked
                    address: softwareSettings.ServerAddress.Address
                    onAddressChanged: {softwareSettings.ServerAddress.Address = address}
                    port: softwareSettings.ServerAddress.Port
                    onPortChanged: {softwareSettings.ServerAddress.Port = port}
                }
            }
        }
    }
}
