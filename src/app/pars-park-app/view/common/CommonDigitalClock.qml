import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
   property var locale: Qt.locale()
   property string dateAndTimeString
   function timeChanged() {
      var currentDate = new Date;
      dateAndTimeString = currentDate.toLocaleDateString() + " " + currentDate.toTimeString();
   }

   id: digitalClockRectangleId
   color: "transparent"
   Timer {
      interval: 100
      running: true
      repeat: true
      onTriggered: digitalClockRectangleId.timeChanged()
   }
   Label {
      id: digitalClockTextId
      text: dateAndTimeString
   }
}
