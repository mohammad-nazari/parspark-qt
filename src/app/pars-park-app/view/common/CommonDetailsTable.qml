import QtQuick 2.13
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
   id: detailsTableRectangleId
   color: 'teal'
   implicitWidth: parent.width
   implicitHeight: parent.height
   TableView {
      id: detailsTableId
      width: parent.width
      height: parent.height
//      LayoutMirroring.enabled: true
//      LayoutMirroring.childrenInherit: true
      anchors.left: parent.left   // anchor left becomes right
      TableViewColumn {
         id: cardIdId
         role: "cardId"
         title: qsTr("Card ID")
      }
      TableViewColumn {
         id: enterPlateNoId
         role: "enterPlateNo"
         title: qsTr("Enter Plate No.")
      }
      TableViewColumn {
         id: exitPlateNoId
         role: "exitPlateNo"
         title: qsTr("Exit Plate No.")
      }
      TableViewColumn {
         id: enterTimeId
         role: "enterTime"
         title: qsTr("Enter Time")
      }
      TableViewColumn {
         id: exitTimeId
         role: "exitTime"
         title: qsTr("Exit Time")
      }
      TableViewColumn {
         id: durationId
         role: "duration"
         title: qsTr("Duration")
      }
      TableViewColumn {
         id: costId
         role: "cost"
         title: qsTr("Cost")
      }
      TableViewColumn {
         id: subTypeId
         role: "subType"
         title: qsTr("Sub Type")
      }
      TableViewColumn {
         id: detailsId
         role: "details"
         title: qsTr("Details")
      }
      TableViewColumn {
         id: printId
         role: "print"
         title: qsTr("Print")
      }
      style: TableViewStyle {
         itemDelegate: Rectangle {
            border.width: 1
            width: 200
            height: 200
            Rectangle {
               border.width: 1
               width: 200
               height: 200
            }
         }
      }
   }
}
