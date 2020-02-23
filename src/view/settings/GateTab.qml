import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column {
   padding: 10
   spacing: 2
   GroupBox {
      id: controlEnterGateGroupBoxId
      title: qsTr("Control Enter Gate")
      checkable: true
      Row {
         leftPadding: 5
         spacing: 5
         CommonCOMPort {
            id:  enterGateCompPortId
         }
         Column {
            leftPadding: 5
            spacing: 2
            GroupBox {
               ExclusiveGroup {
                  id: openEnterGateOptions
               }
               Column {
                  leftPadding: 5
                  spacing: 2
                  RadioButton{
                     id: openEnterGateAutoRadioButtonId
                     text: qsTr("Open auto(By card)")
                     exclusiveGroup: openEnterGateOptions
                     checked: true
                  }
                  RadioButton{
                     id: openEnterGateManuallyRadioButtonId
                     text: qsTr("Open manually")
                     exclusiveGroup: openEnterGateOptions
                  }
               }
            }
            GroupBox {
               ExclusiveGroup {
                  id: closeEnterGateOptions
               }
               Column {
                  leftPadding: 5
                  spacing: 2
                  Row{
                     RadioButton{
                        id: closeEnterGateAfterRadioButtonId
                        text: qsTr("Close after(Seconds)")
                        exclusiveGroup: closeEnterGateOptions
                        checked: true
                     }
                     CommonNumericComboBox{
                        id: closeEnterGateAfterCommonNumericComboBoxId
                        enabled: closeEnterGateAfterRadioButtonId.checked
                        labelText: ""
                        labelWidth: 0
                        minimumValue: 10
                        maximumValue: 60
                     }
                  }
                  RadioButton{
                     id: closeEnterGateManuallyRadioButtonId
                     text: qsTr("Close manually")
                     exclusiveGroup: closeEnterGateOptions
                  }
               }
            }
         }
      }
   }
   GroupBox {
       id: controlExitGateGroupBoxId
      title: qsTr("Control Exit Gate")
      checkable: true
      Row {
         leftPadding: 5
         spacing: 5
         CommonCOMPort {
            id:  exitGateCompPortId
         }
         Column {
            leftPadding: 5
            spacing: 2
            GroupBox {
               ExclusiveGroup {
                  id: openExitGateOptions
               }
               Column {
                  leftPadding: 5
                  spacing: 2
                  RadioButton{
                     id: openExitGateAutoRadioButtonId
                     text: "Close auto(By card)"
                     exclusiveGroup: openExitGateOptions
                     checked: true
                  }
                  RadioButton{
                     id: openExitGateManuallyRadioButtonId
                     text: "Close manually"
                     exclusiveGroup: openExitGateOptions
                  }
               }
            }
            GroupBox {
               ExclusiveGroup {
                  id: closeExitGateOptions
               }
               Column {
                  leftPadding: 5
                  spacing: 2
                  Row{
                     RadioButton{
                        id: closeExitGateAfterRadioButtonId
                        text: qsTr("Close after(Seconds)")
                        exclusiveGroup: closeExitGateOptions
                        checked: true
                     }
                     CommonNumericComboBox{
                        id: closeExitGateAfterCommonNumericComboBoxId
                        enabled: closeExitGateAfterRadioButtonId.checked
                        labelText: ""
                        labelWidth: 0
                        minimumValue: 10
                        maximumValue: 60
                     }
                  }
                  RadioButton{
                     id: closeExitGateManuallyRadioButtonId
                     text: qsTr("Close manually")
                     exclusiveGroup: closeExitGateOptions
                  }
               }
            }
         }
      }
   }
}
