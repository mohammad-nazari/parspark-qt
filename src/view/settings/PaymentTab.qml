import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/view/common"

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
      checked: paymentSettings.citizenDevice.enable
      onCheckedChanged: {paymentSettings.citizenDevice.enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonCOMPort {
            id: enterCardReaderComPortId
            address: paymentSettings.citizenDevice.address.portName
            onAddressChanged: {paymentSettings.citizenDevice.address.portName = address}
            baudRate: paymentSettings.citizenDevice.address.baudRate
            onBaudRateChanged: {paymentSettings.citizenDevice.address.baudRate = baudRate}
         }
         CheckBox{
            id: directSendToCitizenDeviceCheckBoxId
            text: "Direct send cost value to citizen device"
            checked: paymentSettings.citizenDevice.sendDirect
            onCheckedChanged: {paymentSettings.citizenDevice.sendDirect = checked}
         }
      }
   }
   GroupBox {
      id: payWithPOSCardGroupBoxId
      title: qsTr("Pay With POS Card")
      checkable: true
      checked: paymentSettings.posDevice.enable
      onCheckedChanged: {paymentSettings.posDevice.enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonCOMPort {
            id: exitCardReaderComPortId
            address: paymentSettings.posDevice.address.portName
            onAddressChanged: {paymentSettings.posDevice.address.portName = address}
            baudRate: paymentSettings.posDevice.address.baudRate
            onBaudRateChanged: {paymentSettings.posDevice.address.baudRate = baudRate}
         }
         CheckBox{
            id: directSendToPOSDeviceCheckBoxId
            text: "Direct send cost value to POS device"
            checked: paymentSettings.posDevice.sendDirect
            onCheckedChanged: {paymentSettings.posDevice.sendDirect = checked}
         }
      }
   }
}
