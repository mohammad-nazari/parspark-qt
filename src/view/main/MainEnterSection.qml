import QtQuick 2.13
import QtQuick.Layouts 1.12
import "qrc:/src/view/common"

Rectangle{
   id: enterRectangleId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // Width is provided by 200px from 640px relation from main window Width
   Layout.preferredWidth: mainWindowId.width / mainWindowId.height < relativeSize ? parent.width * 5 / 16 : mainWindowId.height * relativeSize * 5 / 16
   Layout.preferredHeight: parent.height
   Layout.maximumWidth: 300
   ColumnLayout{
      id: enterColumnLayoutId
      spacing: 0
      width: enterRectangleId.width
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
      GridLayout{
         id: enterButtonsGridLayoutId
         Layout.margins: 2
         Layout.fillWidth: true
         Layout.fillHeight: true
         // It is provided by 180 in 45 relation between width and height
         Layout.preferredWidth:(parent.width / 2) - 4
         Layout.preferredHeight: width / 4
         rows: 2
         columns: 2
         CommonButton{
            id:enterEnterButtonId
            buttonText: "Enter"
            buttonToolTipText: ""
         }
         CommonButton{
            id:enterBlackListButtonId
            buttonText: "Black List"
            buttonToolTipText: ""
         }
         CommonButton{
            id:enterOpenRoadBlockButtonId
            buttonText: "Open Gate"
            buttonToolTipText: ""
         }
         CommonButton{
            id:enterCloseRoadBlockButtonId
            buttonText: "Close Gate"
            buttonToolTipText: ""
         }
      }
      CommonParkingCapacity{
         id: capacityId
      }
   }
}
