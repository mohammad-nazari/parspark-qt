import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/app/pars-park-app/view/common"

Row{
   property var paymentSettings: ({})
   property var paymentSerialPortsModel: []

   id: paymentId
   padding: 10
   spacing: 2
   GroupBox {
      id: payWithCitizenCardGroupBoxId
      title: qsTr("Pay With Citizen Card")
      checkable: true
      checked: paymentSettings.CitizenDevice.Enable
      onCheckedChanged: {paymentSettings.CitizenDevice.Enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonCOMPort {
            id: enterCardReaderComPortId
            address: paymentSettings.CitizenDevice.ComPortAddress.PortName
            onAddressChanged: {paymentSettings.CitizenDevice.ComPortAddress.PortName = address}
            baudRate: paymentSettings.CitizenDevice.ComPortAddress.BaudRate
            onBaudRateChanged: {paymentSettings.CitizenDevice.ComPortAddress.BaudRate = baudRate}
         }
         CheckBox{
            id: directSendToCitizenDeviceCheckBoxId
            text: "Direct send cost value to citizen device"
            checked: paymentSettings.CitizenDevice.SendDirect
            onCheckedChanged: {paymentSettings.CitizenDevice.SendDirect = checked}
         }
      }
   }
   GroupBox {
      id: payWithPOSCardGroupBoxId
      title: qsTr("Pay With POS Card")
      checkable: true
      checked: paymentSettings.PosDevice.Enable
      onCheckedChanged: {paymentSettings.PosDevice.Enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonCOMPort {
            id: exitCardReaderComPortId
            address: paymentSettings.PosDevice.ComPortAddress.PortName
            onAddressChanged: {paymentSettings.PosDevice.ComPortAddress.PortName = address}
            baudRate: paymentSettings.PosDevice.ComPortAddress.BaudRate
            onBaudRateChanged: {paymentSettings.PosDevice.ComPortAddress.BaudRate = baudRate}
         }
         CheckBox{
            id: directSendToPOSDeviceCheckBoxId
            text: "Direct send cost value to POS device"
            checked: paymentSettings.PosDevice.SendDirect
            onCheckedChanged: {paymentSettings.PosDevice.SendDirect = checked}
         }
      }
   }
}
