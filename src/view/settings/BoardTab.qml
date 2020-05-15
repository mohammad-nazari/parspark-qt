import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Row{
   property var boardSettings: ({})
   property var boardSerialPortsModel: []

   id: boardId
   padding: 10
   spacing: 10
   GroupBox {
      id: sendPriceGroupBoxId
      title: qsTr("Send Price")
      checkable: true
      checked: boardSettings.price.enable
      onCheckedChanged: {boardSettings.price.enable = checked}
      CommonCOMPort {
         id: priceBoardCompPortId
         comPortModel: boardSerialPortsModel
         address: boardSettings.price.address.portName
         onAddressChanged: {boardSettings.price.address.portName = address}
         baudRate: boardSettings.price.address.baudRate
         onBaudRateChanged: {boardSettings.price.address.baudRate = baudRate}
      }
   }
   GroupBox {
      id: sendCapacityGroupBoxId
      title: qsTr("Send Capacity")
      checkable: true
      checked: boardSettings.capacity.enable
      onCheckedChanged: {boardSettings.capacity.enable = checked}
      Column {
         padding: 5
         spacing: 5
         ExclusiveGroup {
            id: capacityOptions
         }
         Column {
            padding: 5
            spacing: 5
            RadioButton{
               id: sendCapacityToBoardRadioButtonId
               text: qsTr("To board")
               checked: boardSettings.capacity.sendToBoard
               onCheckedChanged: {boardSettings.capacity.sendToBoard = checked}
               exclusiveGroup: capacityOptions
            }
            CommonCOMPort {
               id: capacityBoardCompPortId
               enabled: sendCapacityToBoardRadioButtonId.checked
               comPortModel: boardSerialPortsModel
               address: boardSettings.capacity.address.portName
               onAddressChanged: {boardSettings.capacity.address.portName = address}
               baudRate: boardSettings.capacity.address.baudRate
               onBaudRateChanged: {boardSettings.capacity.address.baudRate = baudRate}
            }
         }
         Column {
            padding: 5
            spacing: 5
            RadioButton{
               id: sendCapacityToServerRadioButtonId
               text: qsTr("To server")
               checked: !boardSettings.capacity.sendToBoard
               onCheckedChanged: {boardSettings.capacity.sendToBoard = !checked}
               exclusiveGroup: capacityOptions
            }
            Column {
               enabled: sendCapacityToServerRadioButtonId.checked
               leftPadding: 5
               spacing: 2
               CommonServer{
                  id: serverId
                  address: boardSettings.capacity.serverAddress.address
                  onAddressChanged: {boardSettings.capacity.serverAddress.address = address}
                  port: boardSettings.capacity.serverAddress.port
                  onPortChanged: {boardSettings.capacity.serverAddress.port = port}
               }
               CommonTextField {
                  id: parkingNameTextFieldId
                  labelText: qsTr("Parking Name:")
                  labelWidth: 100
                  placeholderTextText: qsTr("Enter parking name")
                  textFieldWidth: 200
                  textFieldText: boardSettings.capacity.parkingName
                  onTextFieldTextChanged: {boardSettings.capacity.parkingName = textFieldText}
               }
            }
         }
      }
   }
}
