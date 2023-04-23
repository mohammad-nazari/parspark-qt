import QtQuick 2.13
import QtQuick.Layouts 1.12

Rectangle{
   property string buttonText: qsTr("Edit")
   property string buttonToolTipText: qsTr("Edit plate number")
   property bool readOnlyText: false

   id: plateRectangleId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // It is provided by 180 in 30 relation between width and height
   width: parent.width
   height: width / 6
   RowLayout{
      id: plateRowLayoutId
      anchors.fill: parent
//      layoutDirection: Qt.RightToLeft
      CommonButton{
         onClicked: {
            plateRectangleId.readOnlyText = !plateRectangleId.readOnlyText
            if(plateRectangleId.readOnlyText){
               firstNoId.selectAll()
            }else{
               firstNoId.select(0,0)
            }
         }

         id: plateButtonId
         Layout.preferredWidth: height
         Layout.preferredHeight: parent.height
         buttonText: plateRectangleId.buttonText
         buttonToolTipText: plateRectangleId.buttonToolTipText
      }
      Rectangle {
         id: plateId
         enabled: plateRectangleId.readOnlyText
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
         Layout.preferredWidth: parent.width - plateButtonId.width
         Layout.preferredHeight: parent.height
         Image {
            id: platePictureId
            anchors.fill: parent
            source: "qrc:/image/png/plate.png"
         }
         TextInput  {
            id: firstNoId
            text: qsTr("68")
            x: parent.width / 40 * 5
            font.pixelSize: parent.width / 7 > 1 ? parent.width / 7 : 1
            maximumLength: 2
            selectByMouse: true
            focus: plateRectangleId.readOnlyText
         }
         TextInput  {
            id: alphaId
            text: qsTr("T")
            x: parent.width / 40 * 14
            maximumLength: 1
            font.pixelSize: parent.width / 7 > 1 ? parent.width / 7 : 1
            selectByMouse: true
         }
         TextInput  {
            id: secondNoId
            text: qsTr("269")
            x: parent.width / 40 * 20
            maximumLength: 3
            font.pixelSize: parent.width / 7 > 1 ? parent.width / 7 : 1
            selectByMouse: true
         }
         TextInput  {
            id: thirdNoId
            text: qsTr("93")
            x: parent.width / 40 * 33
            maximumLength: 2
            font.pixelSize: parent.width / 10 > 1 ? parent.width / 10 : 1
            topPadding: parent.height / 4
            selectByMouse: true
         }
      }
   }
}
