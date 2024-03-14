import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Row {
    property var boardSettings: ({})
    property var boardSerialPortsModel: []

    id: boardId
    padding: 10
    spacing: 10
    GroupBox {
        id: sendPriceGroupBoxId
        label: CheckBox {
            id: sendPriceId
            text: qsTr("Send Price")
            checked: boardSettings.PriceBoard.Enable
            onCheckedChanged: {boardSettings.PriceBoard.Enable = checked}
        }
        CommonCOMPort {
            id: priceBoardCompPortId
            enabled: sendPriceId.checked
            address: boardSettings.PriceBoard.Address.PortName
            onAddressChanged: {boardSettings.PriceBoard.Address.PortName = address}
            baudRate: boardSettings.PriceBoard.Address.BaudRate
            onBaudRateChanged: {boardSettings.PriceBoard.Address.BaudRate = baudRate}
        }
    }
    GroupBox {
        id: sendCapacityGroupBoxId
        label: CheckBox {
            id: sendCapacityId
            text: qsTr("Send Capacity")
            checked: boardSettings.CapacityBoard.Enable
            onCheckedChanged: {boardSettings.CapacityBoard.Enable = checked}
        }
        Column {
            enabled: sendCapacityId.checked
            padding: 5
            spacing: 5
            ButtonGroup {
                id: capacityOptions
            }
            Column {
                padding: 5
                spacing: 5
                RadioButton {
                    id: sendCapacityToBoardRadioButtonId
                    text: qsTr("To board")
                    checked: boardSettings.CapacityBoard.SendToBoard
                    onCheckedChanged: {boardSettings.CapacityBoard.SendToBoard = checked}
                    ButtonGroup.group: capacityOptions
                }
                CommonCOMPort {
                    id: capacityBoardCompPortId
                    enabled: sendCapacityToBoardRadioButtonId.checked
                    address: boardSettings.CapacityBoard.ComPortAddress.PortName
                    onAddressChanged: {boardSettings.CapacityBoard.ComPortAddress.PortName = address}
                    baudRate: boardSettings.CapacityBoard.Address.BaudRate
                    onBaudRateChanged: {boardSettings.CapacityBoard.Address.BaudRate = baudRate}
                }
            }
            Column {
                padding: 5
                spacing: 5
                RadioButton {
                    id: sendCapacityToServerRadioButtonId
                    text: qsTr("To server")
                    checked: !boardSettings.CapacityBoard.SendToBoard
                    onCheckedChanged: {boardSettings.CapacityBoard.SendToBoard = !checked}
                    ButtonGroup.group: capacityOptions
                }
                Column {
                    enabled: sendCapacityToServerRadioButtonId.checked
                    leftPadding: 5
                    spacing: 2
                    CommonServer {
                        id: serverId
                        address: boardSettings.CapacityBoard.ServerAddress.Address
                        onAddressChanged: {boardSettings.CapacityBoard.ServerAddress.Address = address}
                        port: boardSettings.CapacityBoard.ServerAddress.Port
                        onPortChanged: {boardSettings.CapacityBoard.ServerAddress.Port = port}
                    }
                    CommonTextField {
                        id: parkingNameTextFieldId
                        labelText: qsTr("Parking Name:")
                        labelWidth: 100
                        placeholderTextText: qsTr("Enter parking name")
                        textFieldWidth: 200
                        textFieldText: boardSettings.CapacityBoard.ParkingName
                        onTextFieldTextChanged: {boardSettings.CapacityBoard.ParkingName = textFieldText}
                    }
                }
            }
        }
    }
}
