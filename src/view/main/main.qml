import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13
import QtQuick.Controls 1.4
import "../common"

ApplicationWindow  {
   property real relativeSize: 1.333334
    property var settings: ({})

   id: mainWindowId
   visible: true
   width: 640
   height: 480
   minimumWidth: 640
   minimumHeight: 480
   title: qsTr("ParsPark")
   Rectangle {
      id: bgId
      anchors.fill: parent
      color: "transparent"
      MainColumnLayout {
         id: columnLayoutId
         anchors.bottomMargin: statusBarId.height
      }
   }
   StatusBar {
      id: statusBarId
      anchors.bottom: parent.bottom
      RowLayout {
         CommonDigitalClock{
            id: digitalClockId
         }
      }
   }
}
