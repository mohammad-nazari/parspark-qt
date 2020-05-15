import QtQuick 2.13
import QtQuick.Layouts 1.12

Rectangle{
   property string buttonText: qsTr("Edit")
   property string buttonToolTipText: qsTr("Edit plate number")
   property bool readOnlyText: false

   id: plateRectanglId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // It is provided by 180 in 30 relation between width and height
   Layout.preferredWidth: parent.width - 20
   Layout.preferredHeight: width / 6
   RowLayout{
      id: plateRowLayoutId
      anchors.fill: parent
//      layoutDirection: Qt.RightToLeft
      CommonButton{
         onClicked: {
            plateRectanglId.readOnlyText = !plateRectanglId.readOnlyText
            if(plateRectanglId.readOnlyText){
               firstNoId.selectAll()
            }else{
               firstNoId.select(0,0)
            }
         }

         id: plateButtonId
         Layout.preferredWidth: height
         Layout.preferredHeight: parent.height
         buttonText: plateRectanglId.buttonText
         buttonToolTipText: plateRectanglId.buttonToolTipText
      }
      Rectangle {
         id: plateId
         enabled: plateRectanglId.readOnlyText
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
            source: "qrc:/src/images/plate.png"
         }
         TextInput  {
            id: firstNoId
            text: qsTr("68")
            x: parent.width / 40 * 5
            font.pixelSize: parent.width / 7
            maximumLength: 2
            selectByMouse: true
            focus: plateRectanglId.readOnlyText
         }
         TextInput  {
            id: alphaId
            text: qsTr("T")
            x: parent.width / 40 * 14
            maximumLength: 1
            font.pixelSize: parent.width / 7
            selectByMouse: true
         }
         TextInput  {
            id: secondNoId
            text: qsTr("269")
            x: parent.width / 40 * 20
            maximumLength: 3
            font.pixelSize: parent.width / 7
            selectByMouse: true
         }
         TextInput  {
            id: thirdNoId
            text: qsTr("93")
            x: parent.width / 40 * 33
            maximumLength: 2
            font.pixelSize: parent.width / 10
            topPadding: parent.height / 4
            selectByMouse: true
         }
      }
   }
}
