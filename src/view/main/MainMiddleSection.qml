import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13
import "qrc:/src/view/common"
import "qrc:/src/view/settings"

import ParsPark.View 1.0

Rectangle{
   id: middleRectangleId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // Width is provided by 240px from 640px relation from main window Width
   Layout.preferredWidth: mainWindowId.width / mainWindowId.height < relativeSize ? parent.width * 3 / 8 : mainWindowId.width - (2 * (mainWindowId.height * relativeSize * 5 / 16))
   Layout.preferredHeight: parent.height
   ColumnLayout{
      id: middleColumnLayoutId
      spacing: 0
      anchors.fill: parent
      Rectangle{
         function openForm(formName) {
            var formAddress = "/src/view/" + formName + "/" + formName + ".qml";
            var component = Qt.createComponent(formAddress);
            var window = component.createObject(parent);
         }

         id: menuRectangleId
         Layout.fillWidth: true
         Layout.fillHeight: true
         Layout.preferredWidth: parent.width
         Layout.preferredHeight: width / 8
         RowLayout{
            id: menuRowLayoutId
            spacing: 5
            anchors.fill: parent
                        layoutDirection: Qt.RightToLeft
            ListModel{
               id: menuItemsId
               ListElement{formName: qsTr("settings"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Change settings"); menuImageSource: qsTr("qrc:/image/png/Settings32.png")}
               ListElement{formName: qsTr("users"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Add/Remove/Edit users"); menuImageSource: qsTr("qrc:/image/png/users64.png")}
               ListElement{formName: qsTr("subscriptions"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Add/Remove/Edit subscriptions"); menuImageSource: qsTr("qrc:/image/png/carusers64.png")}
               ListElement{formName: qsTr("block-list"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Add/Remove/Edit block list"); menuImageSource: qsTr("qrc:/image/png/Stop64.png")}
               ListElement{formName: qsTr("reports"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Get reports"); menuImageSource: qsTr("qrc:/image/png/statistica64.png")}
               ListElement{formName: qsTr("lost-cards"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Add/Remove/Report lost cards"); menuImageSource: qsTr("qrc:/image/png/Card-Reader64.png")}
               ListElement{formName: qsTr("about"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("About ParsPark application"); menuImageSource: qsTr("qrc:/image/png/About64.png")}
               ListElement{formName: qsTr("exit"); menuButtonText: qsTr(""); menuButtonToolTipText: qsTr("Exit from application"); menuImageSource: qsTr("qrc:/image/png/exit64.png")}
            }
            Repeater{
               model: menuItemsId
               delegate: menuItemId
            }
         }
         Component{
            id: menuItemId
            CommonButton{
               onClicked: {
                  menuRectangleId.openForm(formName);
               }
               buttonText: menuButtonText
               buttonToolTipText: menuButtonToolTipText
               imageSource: menuImageSource
            }
         }
      }
      Rectangle{
         id: detailsRectangleId
         Layout.fillWidth: true
         Layout.fillHeight: true
         Layout.preferredWidth: parent.width
         Layout.preferredHeight: parent.height - (costInfoRectangleId.height + menuRectangleId.height)
         TabBar {
            id: tabBarId
            width: parent.width
            //            LayoutMirroring.enabled: true
            //            LayoutMirroring.childrenInherit: true
            ListModel{
               id: tabBarItemsId
               ListElement{tabButtonName: qsTr("All")}
               ListElement{tabButtonName: qsTr("Enter")}
               ListElement{tabButtonName: qsTr("Exit")}
               ListElement{tabButtonName: qsTr("In Camera")}
               ListElement{tabButtonName: qsTr("Out Camera")}
               ListElement{tabButtonName: qsTr("In/Out Camera")}
            }
            Repeater{
               model: tabBarItemsId
               delegate: tabBarItemId
            }
            Component{
               id: tabBarItemId
               TabButton {
                  id: tabButtonId
                  property bool isMouseArea: false
                  text: tabButtonName
                  hoverEnabled: true
                  z:0
                  MouseArea
                  {
                     id: mouseAreaId
                     anchors.fill: parent
                     cursorShape: Qt.PointingHandCursor
                     hoverEnabled: true
                     onEntered: isMouseArea = true
                     onExited: isMouseArea = false
                     onClicked: tabBarId.currentIndex = model.index
                  }
                  ToolTip{
                     text: tabButtonName
                     timeout : 5000
                     visible: isMouseArea && tabButtonName != ""
                     background: Rectangle {
                        id: bgToolTipId
                        radius: 10
                        gradient: Gradient {
                           GradientStop {
                              position: 0.00
                              color: "white"
                           }
                           GradientStop {
                              position: 1.00
                              color: "lightcyan"
                           }
                        }
                     }
                  }
               }
            }
         }
         StackLayout {
            width: parent.width
            height: parent.height - tabBarId.height
            anchors.top: tabBarId.bottom
            currentIndex: tabBarId.currentIndex
            CommonDetailsTable{
               id: allDetailsId
            }
            CommonDetailsTable{
               id: enterDetailsId
            }
            CommonDetailsTable{
               id: exitDetailsId
            }
         }
      }
      Rectangle{
         id: costInfoRectangleId
         color: "transparent"
         Layout.fillWidth: true
         Layout.fillHeight: true
         Layout.preferredWidth: parent.width
         Layout.preferredHeight: parent.height / 10
         Layout.maximumHeight: 200
         RowLayout{
            id: costInfoColumnLayoutId
            spacing: 0
            anchors.fill: parent
                        layoutDirection: Qt.RightToLeft
            CommonStatus{
               id: costValueId
               Layout.fillWidth: true
               Layout.fillHeight: true
               Layout.preferredWidth: parent.width * 0.6
               Layout.preferredHeight: parent.height
               statusString: qsTr("Waiting for new exit")
            }
            Rectangle{
               id: costActionsId
               color: "transparent"
               Layout.fillWidth: true
               Layout.fillHeight: true
               Layout.preferredWidth: parent.width * 0.3
               Layout.preferredHeight: parent.height
               ColumnLayout{
                  spacing: 0
                  anchors.fill: parent
                  Rectangle{
                     id: durationAndPrintRectangleId
                     color: "transparent"
                     Layout.fillWidth: true
                     Layout.fillHeight: true
                     RowLayout{
                        id: durationAndPrintRowLayoutId
                        spacing: 0
                        anchors.fill: parent
                                                layoutDirection: Qt.RightToLeft
                        CommonStatus{
                           id: durationStatusId
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           Layout.preferredWidth: parent.width - printReceiptButtonId.width
                           Layout.preferredHeight: parent.height
                           statusString: qsTr("00 00:00:00")
                        }
                        CommonButton{
                           id: printReceiptButtonId
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           Layout.preferredWidth: height
                           Layout.preferredHeight: parent.height
                           buttonText: ""
                           buttonToolTipText: qsTr("Print receipt")
                           Image {
                              id: printReceiptImageId
                              anchors.fill: parent
                              source: "qrc:/image/png/Printer64.png"
                           }
                        }
                     }
                  }
                  Rectangle{
                     color: "transparent"
                     Layout.fillWidth: true
                     Layout.fillHeight: true
                     RowLayout{
                        spacing: 0
                        anchors.fill: parent
                                                layoutDirection: Qt.RightToLeft
                        CommonButton{
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           buttonText: qsTr("EPay")
                           buttonToolTipText: qsTr("Pay by ECart")
                        }
                        CommonButton{
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           buttonText: qsTr("POS")
                           buttonToolTipText: qsTr("Pay by POS")
                        }
                     }
                  }
               }
            }
         }
      }
   }
}
