import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Row{
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
         }
         CheckBox{
            id: activeExieSectionCheckBoxid
            text: qsTr("Active exit section")
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
               checked: true
            }
            CommonSpinBox{
               id: portNumberSpinBoxId
               enabled: serverSoftwareTypeRadioButtonId.checked
               labelText: qsTr("Port number:")
               labelWidth: 100
               minimumValueValue: 1
               maximumValueValue: 65535
               spinBoxValue: 50001
            }
         }
         Column{
            leftPadding: 5
            spacing: 2
            RadioButton{
               id: clientSoftwareTypeRadioButtonId
               text: qsTr("Client type")
               exclusiveGroup: softwareTypeOptions
            }
            CommonServer {
               id: serverId
               enabled: clientSoftwareTypeRadioButtonId.checked
            }
         }
      }
   }
}
