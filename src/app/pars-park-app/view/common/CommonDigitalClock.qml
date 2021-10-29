import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13

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
