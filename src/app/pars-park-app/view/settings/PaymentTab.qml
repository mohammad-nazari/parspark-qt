import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Row {
    property var paymentSettings: ({})
    property var paymentSerialPortsModel: []

    id: paymentId
    padding: 10
    spacing: 2
    GroupBox {
        id: payWithCitizenCardGroupBoxId
        label: CheckBox {
            id: payWithCitizenCard
            text: qsTr("Pay With Citizen Card")
            checked: paymentSettings.CitizenDevice.Enable
            onCheckedChanged: {paymentSettings.CitizenDevice.Enable = checked}
        }
        Column {
            enabled: payWithCitizenCard.checked
            padding: 5
            spacing: 5
            CommonCOMPort {
                id: enterCardReaderComPortId
                address: paymentSettings.CitizenDevice.ComPortAddress.PortName
                onAddressChanged: {paymentSettings.CitizenDevice.ComPortAddress.PortName = address}
                baudRate: paymentSettings.CitizenDevice.ComPortAddress.BaudRate
                onBaudRateChanged: {paymentSettings.CitizenDevice.ComPortAddress.BaudRate = baudRate}
            }
            CheckBox {
                id: directSendToCitizenDeviceCheckBoxId
                text: "Direct send cost value to citizen device"
                checked: paymentSettings.CitizenDevice.SendDirect
                onCheckedChanged: {paymentSettings.CitizenDevice.SendDirect = checked}
            }
        }
    }
    GroupBox {
        id: payWithPOSCardGroupBoxId
        label: CheckBox {
            id: payWithPosCard
            text: qsTr("Pay With POS Card")
            checked: paymentSettings.PosDevice.Enable
            onCheckedChanged: {paymentSettings.PosDevice.Enable = checked}
        }
        Column {
            enabled: payWithPosCard.checked
            padding: 5
            spacing: 5
            CommonCOMPort {
                id: exitCardReaderComPortId
                address: paymentSettings.PosDevice.ComPortAddress.PortName
                onAddressChanged: {paymentSettings.PosDevice.ComPortAddress.PortName = address}
                baudRate: paymentSettings.PosDevice.ComPortAddress.BaudRate
                onBaudRateChanged: {paymentSettings.PosDevice.ComPortAddress.BaudRate = baudRate}
            }
            CheckBox {
                id: directSendToPOSDeviceCheckBoxId
                text: "Direct send cost value to POS device"
                checked: paymentSettings.PosDevice.SendDirect
                onCheckedChanged: {paymentSettings.PosDevice.SendDirect = checked}
            }
        }
    }
}
