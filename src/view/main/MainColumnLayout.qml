import QtQuick 2.13
import QtQuick.Layouts 1.12

RowLayout {
   id: rowLayoutId
   anchors.fill: parent
   spacing: 0
   MainExitSection{
      id: exitSideId
   }
   MainMiddleSection{
      id: middelSideId
   }
   MainEnterSection{
      id: enterSideId
   }
}
