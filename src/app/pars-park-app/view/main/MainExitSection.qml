import QtQuick 2.13
import QtQuick.Layouts 1.12
import "qrc:/src/app/pars-park-app/view/common"

Rectangle{
   id: rectExitId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // Width is provided by 200px from 640px relation from main window Width
   width: mainWindowId.width / mainWindowId.height < relativeSize ? parent.width * 5 / 16 : mainWindowId.height * relativeSize * 5 / 16
   height: parent.height
   Column{
      id: colExitId
      spacing: 5
      width: parent.width
      CommonStatus{
         id: exitStatusId
         statusString: qsTr("Initializing exit section")
      }
      CommonPlate{
         id: exitEnterPlateId
         enabled: false
         buttonText: qsTr("")
         buttonToolTipText: qsTr("")
      }
      CommonPicture{
         id: exitEnterPictureId
      }
      CommonDateAndTime{
         id: exitEnterDateAndTimeId
      }
      Column{
         id: colButtonsId
         Layout.margins: 2
         Layout.fillWidth: true
         Layout.fillHeight: true
         // It is provided by 180 in 45 relation between width and height
         width: parent.width
         height: width / 4
         Row{
            spacing: parent.width / 30
             height: parent.height / 2
             anchors.horizontalCenter: parent.horizontalCenter
             CommonButton{
                id:exitExitButtonId
                buttonText: qsTr("Exit")
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
             CommonButton{
                id:exitBlackListButtonId
                buttonText: qsTr("Black List")
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
         }
         Row{
            spacing: parent.width / 30
             height: parent.height / 2
             anchors.horizontalCenter: parent.horizontalCenter
             CommonButton{
                id:exitOpenRoadBlockButtonId
                buttonText: qsTr("Open Gate")
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
             CommonButton{
                id:exitCloseRoadBlockButtonId
                buttonText: qsTr("Close Gate")
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
         }
      }
      CommonPlate{
         id: exitExitPlateId
         buttonToolTipText: qsTr("Edit exit car plate number")
      }
      CommonPicture{
         id: exitExitPictureId
      }
      CommonDateAndTime{
         id: exitExitDateAndTimeId
      }
   }
}
