import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column{
   padding: 10
   spacing: 2
   GroupBox {
      id: savePlateNumberGroupBoxId
      title: ("Save Plate Number")
      checkable: true
      Column {
         leftPadding: 5
         spacing: 10
         ExclusiveGroup {
            id: alprOptions
         }
         Column {
            spacing: 2
            RadioButton {
               id: submitWithCameraId
               text: "Submit with camera"
               checked: true
               exclusiveGroup: alprOptions
            }
            Column{
               enabled: submitWithCameraId.checked
               leftPadding: 5
               spacing: 2
               CheckBox{
                  id: allowSaveWithoutEnterCheckBoxId
                  text: ("Allow save without enter plate number")
               }
               CheckBox{
                  id: allowSaveWithoutExitCheckBoxId
                  text: ("Allow save without exit plate number")
               }
            }
         }
         RadioButton {
            id: submitManuallyRadioButtonId
            text: "Submit manually"
            exclusiveGroup: alprOptions
         }
      }
   }
}
