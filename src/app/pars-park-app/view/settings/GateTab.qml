import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Column {
    property var gateSettings: ({})

    id: gateId
    padding: 10
    spacing: 2
    GroupBox {
        id: controlEnterGateGroupBoxId
        label: CheckBox {
            id: controlEnterGate
            text: qsTr("Control Enter Gate")
            checked: gateSettings.EnterGate.Enable
            onCheckedChanged: {gateSettings.EnterGate.Enable = checked}
        }
        Row {
            enabled: controlEnterGate.checked
            leftPadding: 5
            spacing: 5
            CommonCOMPort {
                id: enterGateCompPortId
                address: gateSettings.EnterGate.ComPortAddress.PortName
                onAddressChanged: {gateSettings.EnterGate.ComPortAddress.PortName = address}
                baudRate: gateSettings.EnterGate.ComPortAddress.BaudRate
                onBaudRateChanged: {gateSettings.EnterGate.ComPortAddress.BaudRate = baudRate}
            }
            Column {
                leftPadding: 5
                spacing: 2
                GroupBox {
                    ButtonGroup {
                        id: openEnterGateOptions
                    }
                    Column {
                        leftPadding: 5
                        spacing: 2
                        RadioButton {
                            id: openEnterGateAutoRadioButtonId
                            text: qsTr("Open auto(By card)")
                            ButtonGroup.group: openEnterGateOptions
                            checked: gateSettings.EnterGate.OpenAuto
                            onCheckedChanged: {gateSettings.EnterGate.OpenAuto = checked}
                        }
                        RadioButton {
                            id: openEnterGateManuallyRadioButtonId
                            text: qsTr("Open manually")
                            ButtonGroup.group: openEnterGateOptions
                            checked: !gateSettings.EnterGate.OpenAuto
                            onCheckedChanged: {gateSettings.EnterGate.OpenAuto = !checked}
                        }
                    }
                }
                GroupBox {
                    ButtonGroup {
                        id: closeEnterGateOptions
                    }
                    Column {
                        leftPadding: 5
                        spacing: 2
                        Row {
                            RadioButton {
                                id: closeEnterGateAfterRadioButtonId
                                text: qsTr("Close after(Seconds)")
                                ButtonGroup.group: closeEnterGateOptions
                                checked: gateSettings.EnterGate.OpenAuto
                                onCheckedChanged: {gateSettings.EnterGate.OpenAuto = checked}
                            }
                            CommonNumericComboBox {
                                id: closeEnterGateAfterCommonNumericComboBoxId
                                enabled: closeEnterGateAfterRadioButtonId.checked
                                labelText: ""
                                labelWidth: 0
                                minimumValue: 10
                                maximumValue: 60
                                comboBoxCurrentValue: gateSettings.EnterGate.CloseAfter
                                onComboBoxCurrentValueChanged: {gateSettings.EnterGate.CloseAfter = comboBoxCurrentValue}
                            }
                        }
                        RadioButton {
                            id: closeEnterGateManuallyRadioButtonId
                            text: qsTr("Close manually")
                            ButtonGroup.group: closeEnterGateOptions
                            checked: !gateSettings.EnterGate.OpenAuto
                            onCheckedChanged: {gateSettings.EnterGate.OpenAuto = !checked}
                        }
                    }
                }
            }
        }
    }
    GroupBox {
        id: controlExitGateGroupBoxId
        label: CheckBox {
            id: controlExitGate
            text: qsTr("Control Exit Gate")
            checked: gateSettings.ExitGate.Enable
            onCheckedChanged: {gateSettings.ExitGate.Enable = checked}
        }
        Row {
            enabled: controlExitGate.checked
            leftPadding: 5
            spacing: 5
            CommonCOMPort {
                id: exitGateCompPortId
                address: gateSettings.ExitGate.ComPortAddress.PortName
                onAddressChanged: {gateSettings.ExitGate.ComPortAddress.PortName = address}
                baudRate: gateSettings.ExitGate.ComPortAddress.BaudRate
                onBaudRateChanged: {gateSettings.ExitGate.ComPortAddress.BaudRate = baudRate}
            }
            Column {
                leftPadding: 5
                spacing: 2
                GroupBox {
                    ButtonGroup {
                        id: openExitGateOptions
                    }
                    Column {
                        leftPadding: 5
                        spacing: 2
                        RadioButton {
                            id: openExitGateAutoRadioButtonId
                            text: qsTr("Close auto(By card)")
                            ButtonGroup.group: openExitGateOptions
                            checked: gateSettings.ExitGate.OpenAuto
                            onCheckedChanged: {gateSettings.ExitGate.OpenAuto = checked}
                        }
                        RadioButton {
                            id: openExitGateManuallyRadioButtonId
                            text: qsTr("Close manually")
                            ButtonGroup.group: openExitGateOptions
                            checked: !gateSettings.ExitGate.OpenAuto
                            onCheckedChanged: {gateSettings.ExitGate.OpenAuto = !checked}
                        }
                    }
                }
                GroupBox {
                    ButtonGroup {
                        id: closeExitGateOptions
                    }
                    Column {
                        leftPadding: 5
                        spacing: 2
                        Row {
                            RadioButton {
                                id: closeExitGateAfterRadioButtonId
                                text: qsTr("Close after(Seconds)")
                                ButtonGroup.group: closeExitGateOptions
                                checked: gateSettings.ExitGate.OpenAuto
                                onCheckedChanged: {gateSettings.ExitGate.OpenAuto = checked}
                            }
                            CommonNumericComboBox {
                                id: closeExitGateAfterCommonNumericComboBoxId
                                enabled: closeExitGateAfterRadioButtonId.checked
                                labelText: qsTr("")
                                labelWidth: 0
                                minimumValue: 10
                                maximumValue: 60
                                comboBoxCurrentValue: gateSettings.ExitGate.CloseAfter
                                onComboBoxCurrentValueChanged: {gateSettings.ExitGate.CloseAfter = comboBoxCurrentValue}
                            }
                        }
                        RadioButton {
                            id: closeExitGateManuallyRadioButtonId
                            text: qsTr("Close manually")
                            ButtonGroup.group: closeExitGateOptions
                            checked: !gateSettings.ExitGate.OpenAuto
                            onCheckedChanged: {gateSettings.ExitGate.OpenAuto = !checked}
                        }
                    }
                }
            }
        }
    }
}
