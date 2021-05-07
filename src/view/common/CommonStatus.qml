import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13

Rectangle {
   property string statusString: qsTr("Status")

   id: statusRectangleId
   color: "transparent"
   border{
      color: "black"
      width: 1
   }
   radius: 10
   Layout.margins: 2
   Layout.fillWidth: true
   Layout.fillHeight: true
   // It is provided by 180 in 30 relation between width and height
   width: parent.width
   height: width / 6
   Text {
      id: statusTextId
      anchors.fill: parent
      minimumPixelSize: 1
      fontSizeMode: Text.Fit
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      text: statusString
      font.pixelSize: (parent.height / 2) > 1 ? (parent.height / 2) : 1
   }
}
