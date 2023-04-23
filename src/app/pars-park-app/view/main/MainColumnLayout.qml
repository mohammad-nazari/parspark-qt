import QtQuick 2.13
import QtQuick.Layouts 1.12

Row {
   id: rowLayoutId
   anchors.fill: parent
   spacing: 0
   MainExitSection{
      id: exitSideId
   }
   MainMiddleSection{
      id: middleSideId
   }
   MainEnterSection{
      id: enterSideId
   }
}
