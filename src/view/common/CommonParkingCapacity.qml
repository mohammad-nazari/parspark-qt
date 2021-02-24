import QtQuick 2.13
import QtQuick.Layouts 1.12

RowLayout{
    property int capacity: 1000
    property int empty: 1000

   id: capacityRowLayoutId
   Layout.margins: 2
   Layout.fillWidth: true
   Layout.fillHeight: true
   // It is provided by 180 in 30 relation between width and height
   Layout.preferredWidth: parent.width - 20
   Layout.preferredHeight: width / 6
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
      Layout.preferredWidth: (parent.width / 2) - 2
      Layout.preferredHeight: width / 6
      Text {
          id: fullCapacityTextId
          anchors.fill: parent
          minimumPixelSize: 2
          fontSizeMode: Text.Fit
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          text: capacity
          font.pointSize: parent.height / 2
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
      Layout.preferredWidth: (parent.width / 2) - 2
      Layout.preferredHeight: width / 6
      Text {
          id: emptyCapacityTextId
          anchors.fill: parent
          minimumPixelSize: 2
          fontSizeMode: Text.Fit
          horizontalAlignment: Text.AlignHCenter
          verticalAlignment: Text.AlignVCenter
          text: empty
          font.pointSize: parent.height / 2
      }
   }
}
