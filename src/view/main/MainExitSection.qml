import QtQuick 2.13
import QtQuick.Layouts 1.12
import "../common"

Rectangle{
   id: exitRectangleId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // Width is provided by 200px from 640px relation from main window Width
   Layout.preferredWidth: mainWindowId.width / mainWindowId.height < relativeSize ? parent.width * 5 / 16 : mainWindowId.height * relativeSize * 5 / 16
   Layout.preferredHeight: parent.height
   Layout.maximumWidth: 300
   ColumnLayout{
      id: exitColumnLayoutId
      spacing: 0
      width: exitRectangleId.width
      CommonStatus{
         id: exitStatusId
         statusString: qsTr("Initilaizing exit section")
      }
      CommonPlate{
         id: exitEnterPlateId
         enabled: false
         buttonText: ""
         buttonToolTipText: ""
      }
      CommonPicture{
         id: exitEnterPictureId
      }
      CommonDateAndTime{
         id: exitEnterDateAndTimeId
      }
      GridLayout{
         id: enterButtonsGridLayoutId
         Layout.margins: 1
         Layout.fillWidth: true
         Layout.fillHeight: true
         // It is provided by 180 in 45 relation between width and height
         Layout.preferredWidth:(parent.width / 2) - 4
         Layout.preferredHeight: width / 4
         rows: 2
         columns: 2
         CommonButton{
            id:exitExitButtonId
            buttonText: qsTr("Exit")
            buttonToolTipText: ""
         }
         CommonButton{
            id:exitBlackListButtonId
            buttonText: qsTr("Black List")
            buttonToolTipText: ""
         }
         CommonButton{
            id:exitOpenRoadBlockButtonId
            buttonText: qsTr("Open Gate")
            buttonToolTipText: ""
         }
         CommonButton{
            id:exitCloseRoadBlockButtonId
            buttonText: qsTr("Close Gate")
            buttonToolTipText: ""
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
