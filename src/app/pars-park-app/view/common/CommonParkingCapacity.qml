import QtQuick
import QtQuick.Layouts

Row{
    property int capacity: 1000
    property int empty: 1000

   id: capacityRowLayoutId
   spacing: 2
   Layout.margins: 2
   Layout.fillWidth: true
   Layout.fillHeight: true
   // It is provided by 180 in 30 relation between width and height
   width: parent.width
   height: width / 6
   Rectangle {
      id: fullCapacityRectangleId
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
      width: (parent.width / 2) - 2
      height: width / 4
      Text {
          id: fullCapacityTextId
          anchors.fill: parent
          minimumPixelSize: 1
          fontSizeMode: Text.Fit
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          text: capacity
          font.pixelSize: parent.width / 3 > 1 ? parent.width / 3 : 1
      }
   }
   Rectangle {
      id: emptyCapacityRectangleId
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
      width: (parent.width / 2) - 2
      height: width / 4
      Text {
          id: emptyCapacityTextId
          anchors.fill: parent
          minimumPixelSize: 1
          fontSizeMode: Text.Fit
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          text: empty
          font.pixelSize: parent.width / 3 > 1 ? parent.width / 3 : 1
      }
   }
}
