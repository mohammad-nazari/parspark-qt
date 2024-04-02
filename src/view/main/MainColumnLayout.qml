import QtQuick
import QtQuick.Layouts

import ANAR.ParsPark.View

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
