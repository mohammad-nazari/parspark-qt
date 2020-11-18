import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column {
   property var gateSettings: ({})

   id: gateId
   padding: 10
   spacing: 2
   GroupBox {
      id: controlEnterGateGroupBoxId
      title: qsTr("Control Enter Gate")
      checkable: true
      checked: gateSettings.enter.enable
      onCheckedChanged: {gateSettings.enter.enable = checked}
      Row {
         leftPadding: 5
         spacing: 5
         CommonCOMPort {
            id:  enterGateCompPortId
            address: gateSettings.enter.address.portName
            onAddressChanged: {gateSettings.enter.address.portName = address}
            baudRate: gateSettings.enter.address.baudRate
            onBaudRateChanged: {gateSettings.enter.address.baudRate = baudRate}
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
                     checked: gateSettings.enter.openAuto
                     onCheckedChanged: {gateSettings.enter.openAuto = checked}
                  }
                  RadioButton{
                     id: openEnterGateManuallyRadioButtonId
                     text: qsTr("Open manually")
                     exclusiveGroup: openEnterGateOptions
                     checked: !gateSettings.enter.openAuto
                     onCheckedChanged: {gateSettings.enter.openAuto = !checked}
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
                        checked: gateSettings.enter.openAuto
                        onCheckedChanged: {gateSettings.enter.openAuto = checked}
                     }
                     CommonNumericComboBox{
                        id: closeEnterGateAfterCommonNumericComboBoxId
                        enabled: closeEnterGateAfterRadioButtonId.checked
                        labelText: ""
                        labelWidth: 0
                        minimumValue: 10
                        maximumValue: 60
                        comboBoxCurrentValue: gateSettings.enter.closeAfter
                        onComboBoxCurrentValueChanged: {gateSettings.enter.closeAfter = comboBoxCurrentValue}
                     }
                  }
                  RadioButton{
                     id: closeEnterGateManuallyRadioButtonId
                     text: qsTr("Close manually")
                     exclusiveGroup: closeEnterGateOptions
                     checked: !gateSettings.enter.openAuto
                     onCheckedChanged: {gateSettings.enter.openAuto = !checked}
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
      checked: gateSettings.exit.enable
      onCheckedChanged: {gateSettings.exit.enable = checked}
      Row {
         leftPadding: 5
         spacing: 5
         CommonCOMPort {
            id:  exitGateCompPortId
            address: gateSettings.exit.address.portName
            onAddressChanged: {gateSettings.exit.address.portName = address}
            baudRate: gateSettings.exit.address.baudRate
            onBaudRateChanged: {gateSettings.exit.address.baudRate = baudRate}
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
                     text: qsTr("Close auto(By card)")
                     exclusiveGroup: openExitGateOptions
                     checked: gateSettings.exit.openAuto
                     onCheckedChanged: {gateSettings.exit.openAuto = checked}
                  }
                  RadioButton{
                     id: openExitGateManuallyRadioButtonId
                     text: qsTr("Close manually")
                     exclusiveGroup: openExitGateOptions
                     checked: !gateSettings.exit.openAuto
                     onCheckedChanged: {gateSettings.exit.openAuto = !checked}
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
                        checked: gateSettings.exit.openAuto
                        onCheckedChanged: {gateSettings.exit.openAuto = checked}
                     }
                     CommonNumericComboBox{
                        id: closeExitGateAfterCommonNumericComboBoxId
                        enabled: closeExitGateAfterRadioButtonId.checked
                        labelText: qsTr("")
                        labelWidth: 0
                        minimumValue: 10
                        maximumValue: 60
                        comboBoxCurrentValue: gateSettings.exit.closeAfter
                        onComboBoxCurrentValueChanged: {gateSettings.exit.closeAfter = comboBoxCurrentValue}
                     }
                  }
                  RadioButton{
                     id: closeExitGateManuallyRadioButtonId
                     text: qsTr("Close manually")
                     exclusiveGroup: closeExitGateOptions
                     checked: !gateSettings.exit.openAuto
                     onCheckedChanged: {gateSettings.exit.openAuto = !checked}
                  }
               }
            }
         }
      }
   }
}
