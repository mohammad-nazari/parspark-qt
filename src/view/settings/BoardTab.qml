import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Row{
   padding: 10
   spacing: 10
   GroupBox {
      id: sendPriceGroupBoxId
      title: qsTr("Send Price")
      checkable: true
      CommonCOMPort {
         id: priceBoardCompPortId
      }
   }
   GroupBox {
      id: sendCapacityGroupBoxId
      title: qsTr("Send Capacity")
      checkable: true
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
               checked: true
               exclusiveGroup: capacityOptions
            }
            CommonCOMPort {
               id: capacityBoardCompPortId
               enabled: sendCapacityToBoardRadioButtonId.checked
            }
         }
         Column {
            padding: 5
            spacing: 5
            RadioButton{
               id: sendCapacityToServerRadioButtonId
               text: qsTr("To server")
               exclusiveGroup: capacityOptions
            }
            Column {
               enabled: sendCapacityToServerRadioButtonId.checked
               leftPadding: 5
               spacing: 2
               CommonServer{
                  id: serverId
               }
               CommonTextField {
                  id: parkingNameTextFieldId
                  labelText: qsTr("Parking Name:")
                  labelWidth: 100
                  placeholderTextText: qsTr("Enter parking name")
                  textFieldWidth: 200
               }
            }
         }
      }
   }
}
