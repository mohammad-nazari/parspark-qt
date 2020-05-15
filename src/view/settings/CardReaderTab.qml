import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Row{
   property var cardReaderSettings: ({})
   property var cardRaderSerialPortsModel: []

   id: cardReaderId
   padding: 10
   spacing: 2
   GroupBox {
      title: qsTr("Enter Card Reader")
      CommonCOMPort{
         id: enterCardReaderCompPortId
         comPortModel: cardRaderSerialPortsModel
         address: cardReaderSettings.enter.portName
         onAddressChanged: {cardReaderSettings.enter.portName = address}
         baudRate: cardReaderSettings.enter.baudRate
         onBaudRateChanged: {cardReaderSettings.enter.baudRate = baudRate}
      }
   }
   GroupBox {
      title: qsTr("Exit Card Reader")
      CommonCOMPort{
         id: exitCardReaderCompPortId
         comPortModel: cardRaderSerialPortsModel
         address: cardReaderSettings.exit.portName
         onAddressChanged: {cardReaderSettings.exit.portName = address}
         baudRate: cardReaderSettings.exit.baudRate
         onBaudRateChanged: {cardReaderSettings.exit.baudRate = baudRate}
      }
   }
}
