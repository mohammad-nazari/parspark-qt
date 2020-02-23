import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Row{
   padding: 10
   spacing: 2
   GroupBox {
      id: payWithCitizenCardGroupBoxId
      title: qsTr("Pay With Citizen Card")
      checkable: true
      Column{
         padding: 5
         spacing: 5
         CommonCOMPort {
            id: enterCardReaderComPortId
         }
         CheckBox{
            id: directSendToCitizenDeviceCheckBoxId
            text: "Direct send cost value to citizen device"
         }
      }
   }
   GroupBox {
      id: payWithPOSCardGroupBoxId
      title: qsTr("Pay With POS Card")
      checkable: true
      Column{
         padding: 5
         spacing: 5
         CommonCOMPort {
            id: exitCardReaderComPortId
         }
         CheckBox{
            id: directSendToPOSDeviceCheckBoxId
            text: "Direct send cost value to POS device"
         }
      }
   }
}
