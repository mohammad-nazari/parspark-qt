import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/app/pars-park-app/view/common"

Row{
   property var cardReaderSettings: ({})

   id: cardReaderId
   padding: 10
   spacing: 2
   GroupBox {
      title: qsTr("Enter Card Reader")
      CommonCOMPort{
         id: enterCardReaderCompPortId
         address: cardReaderSettings.EnterCardReader.PortName
         onAddressChanged: {cardReaderSettings.EnterCardReader.PortName = address}
         baudRate: cardReaderSettings.EnterCardReader.BaudRate
         onBaudRateChanged: {cardReaderSettings.EnterCardReader.BaudRate = baudRate}
      }
   }
   GroupBox {
      title: qsTr("Exit Card Reader")
      CommonCOMPort{
         id: exitCardReaderCompPortId
         address: cardReaderSettings.ExitCardReader.PortName
         onAddressChanged: {cardReaderSettings.ExitCardReader.PortName = address}
         baudRate: cardReaderSettings.ExitCardReader.BaudRate
         onBaudRateChanged: {cardReaderSettings.ExitCardReader.BaudRate = baudRate}
      }
   }
}
