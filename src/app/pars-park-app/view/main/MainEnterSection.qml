import QtQuick
import QtQuick.Layouts
import "qrc:/src/app/pars-park-app/view/common"

Rectangle{
   id: rectEnterId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // Width is provided by 200px from 640px relation from main window Width
   width: mainApplicationWindowId.width / mainApplicationWindowId.height < relativeSize ? parent.width * 5 / 16 : mainApplicationWindowId.height * relativeSize * 5 / 16
   height: parent.height
   Column{
      id: colEnterId
      spacing: 5
      width: parent.width
      CommonStatus{
         id: enterStatusId
         statusString: "Initializing enter section"
      }
      CommonPlate{
         id: enterPlateId
         buttonToolTipText: "Edit entered car plate number"
      }
      CommonPicture{
         id: enterPictureId
      }
      CommonDateAndTime{
         id: enterDateAndTimeId
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
                id:enterEnterButtonId
                buttonText: "Enter"
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
             CommonButton{
                id:enterBlackListButtonId
                buttonText: "Black List"
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
                id:enterOpenRoadBlockButtonId
                buttonText: "Open Gate"
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
             CommonButton{
                id:enterCloseRoadBlockButtonId
                buttonText: "Close Gate"
                buttonToolTipText: ""
                width: (colButtonsId.width / 5) * 2
                height: parent.height
             }
         }
      }
      CommonParkingCapacity{
         id: capacityId
      }
   }
}
