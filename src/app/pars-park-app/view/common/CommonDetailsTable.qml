import QtQuick
import QtQuick.Controls
import Qt.labs.qmlmodels
// import QtQuick.Controls.Styles

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
        anchors.left: parent.left   // anchor left becomes right1
        model: TableModel {
            TableModelColumn {
                id: cardIdId
                display: qsTr("Card ID")
//                role: "cardId"
            }
            TableModelColumn {
                id: enterPlateNoId
//                role: "enterPlateNo"
                display: qsTr("Enter Plate No.")
            }
            TableModelColumn {
                id: exitPlateNoId
//                role: "exitPlateNo"
                display: qsTr("Exit Plate No.")
            }
            TableModelColumn {
                id: enterTimeId
//                role: "enterTime"
                display: qsTr("Enter Time")
            }
            TableModelColumn {
                id: exitTimeId
//                role: "exitTime"
                display: qsTr("Exit Time")
            }
            TableModelColumn {
                id: durationId
//                role: "duration"
                display: qsTr("Duration")
            }
            TableModelColumn {
                id: costId
//                role: "cost"
                display: qsTr("Cost")
            }
            TableModelColumn {
                id: subTypeId
//                role: "subType"
                display: qsTr("Sub Type")
            }
            TableModelColumn {
                id: detailsId
//                role: "details"
                display: qsTr("Details")
            }
            TableModelColumn {
                id: printId
//                role: "print"
                display: qsTr("Print")
            }
        }
        /*      style: TableViewStyle {
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
              }*/
    }
}
