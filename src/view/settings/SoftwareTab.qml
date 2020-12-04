import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/view/common"

Row{
   property var softwareSettings: ({})

   id: softwareId
   padding: 10
   spacing: 2
   GroupBox {
      title: qsTr("Active Sections")
      Column{
         leftPadding: 5
         spacing: 5
         CheckBox{
            id: activeEnterSectionCheckBoxid
            text: qsTr("Active enter section")
            checked: softwareSettings.activeEnter
            onCheckedChanged: {softwareSettings.activeEnter = checked}
         }
         CheckBox{
            id: activeExieSectionCheckBoxid
            text: qsTr("Active exit section")
            checked: softwareSettings.activeExit
            onCheckedChanged: {softwareSettings.activeExit = checked}
         }
      }
   }
   GroupBox{
      title: qsTr("Software Type")
      Column{
         leftPadding: 5
         spacing: 10
         ExclusiveGroup {
            id: softwareTypeOptions
         }
         Column{
            leftPadding: 5
            spacing: 2
            RadioButton{
               id: serverSoftwareTypeRadioButtonId
               text: qsTr("Server type")
               exclusiveGroup: softwareTypeOptions
               checked: softwareSettings.asServer
               onCheckedChanged: {softwareSettings.asServer = checked}
            }
            CommonSpinBox{
               id: portNumberSpinBoxId
               enabled: serverSoftwareTypeRadioButtonId.checked
               labelText: qsTr("Port number:")
               labelWidth: 100
               minimumValueValue: 1
               maximumValueValue: 65535
               spinBoxValue: softwareSettings.port
               onSpinBoxValueChanged: {softwareSettings.port = spinBoxValue}
            }
         }
         Column{
            leftPadding: 5
            spacing: 2
            RadioButton{
               id: clientSoftwareTypeRadioButtonId
               text: qsTr("Client type")
               exclusiveGroup: softwareTypeOptions
               checked: !softwareSettings.asServer
               onCheckedChanged: {softwareSettings.asServer = !checked}
            }
            CommonServer {
               id: serverId
               enabled: clientSoftwareTypeRadioButtonId.checked
               address: softwareSettings.serverAddress.address
               onAddressChanged: {softwareSettings.serverAddress.address = address}
               port: softwareSettings.serverAddress.port
               onPortChanged: {softwareSettings.serverAddress.port = port}
            }
         }
      }
   }
}
