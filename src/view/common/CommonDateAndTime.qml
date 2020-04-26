import QtQuick 2.13
import QtQuick.Layouts 1.12

Rectangle {
   property string dateAndTimeString: getDateAndTime()
   function getDateAndTime() {
      var currentDate = new Date;
      dateAndTimeString = currentDate.toLocaleDateString() + " " + currentDate.toTimeString();
   }

   id: dateAndTimeId
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
   Layout.preferredWidth: parent.width - 20
   Layout.preferredHeight: width / 6
   Text {
      id: dateAndTimeTextId
      anchors.centerIn: parent
      text: dateAndTimeString
      font.pointSize: dateAndTimeId.width / 25
   }
}
