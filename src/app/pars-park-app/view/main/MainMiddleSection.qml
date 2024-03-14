import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"
import "qrc:/src/app/pars-park-app/view/settings"

import ANAR.ParsPark.View

Rectangle{
   id: middleRectangleId
   color: "transparent"
   Layout.fillWidth: true
   Layout.fillHeight: true
   // Width is provided by 240px from 640px relation from main window Width
   width: mainApplicationWindowId.width / mainApplicationWindowId.height < relativeSize ? parent.width * 3 / 8 : mainApplicationWindowId.width - (2 * (mainApplicationWindowId.height * relativeSize * 5 / 16))
   height: parent.height - 20
   Column{
      id: middleColumnLayoutId
      spacing: 5
      width: middleRectangleId.width
      height: middleRectangleId.height
      Rectangle{
         function openForm(formName) {
            var formAddress = "/src/app/pars-park-app/view/" + formName + "/" + formName + ".qml";
            var component = Qt.createComponent(formAddress);
            var window = component.createObject(parent);
         }

         id: menuRectangleId
         Layout.fillWidth: true
         Layout.fillHeight: true
         width: parent.width
         height: width / 8
         Row{
            id: menuRowLayoutId
            spacing: parent.width / 50
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
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
                    if(formName=="exit"){
                        close();
                    }
                  menuRectangleId.openForm(formName);
               }
               buttonText: menuButtonText
               buttonToolTipText: menuButtonToolTipText
               imageSource: menuImageSource
               height: parent.height * 4 / 5
               width: height
               anchors.verticalCenter: parent.verticalCenter
            }
         }
      }
      Rectangle{
         id: detailsRectangleId
         Layout.fillWidth: true
         Layout.fillHeight: true
         width: parent.width
         height: parent.height - (costInfoRectangleId.height + menuRectangleId.height)
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
         width: parent.width
         height: parent.height / 10
         Row{
            id: costInfoColumnLayoutId
            width: parent.width
            height: parent.height
            spacing: 2
//            layoutDirection: Qt.RightToLeft
            CommonStatus{
               id: costValueId
               Layout.fillWidth: true
               Layout.fillHeight: true
               width: parent.width * 0.6
               height: parent.height
               statusString: qsTr("Waiting for new exit")
            }
            Rectangle{
               id: costActionsId
               color: "transparent"
               Layout.fillWidth: true
               Layout.fillHeight: true
               width: parent.width * 0.4
               height: parent.height
               Column{
                  spacing: 2
                  width: parent.width
                  height: parent.height
                  Rectangle{
                     id: durationAndPrintRectangleId
                     color: "transparent"
                     Layout.fillWidth: true
                     Layout.fillHeight: true
                     width: parent.width
                     height: parent.height / 2
                     Row{
                        id: durationAndPrintRowLayoutId
                        spacing: 2
                        height: parent.height
                        anchors.horizontalCenter: durationAndPrintRectangleId.horizontalCenter
//                        layoutDirection: Qt.RightToLeft
                        CommonStatus{
                           id: durationStatusId
                           width: durationAndPrintRectangleId.width * 0.6
                           height: parent.height
                           statusString: qsTr("00 00:00:00")
                        }
                        Rectangle{
                           color: "transparent"
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           width: durationAndPrintRectangleId.width * 0.4
                           height: parent.height
                            CommonButton{
                               id: printReceiptButtonId
                               Layout.fillWidth: true
                               Layout.fillHeight: true
                               height: parent.height
                               width: height
                               buttonText: ""
                               buttonToolTipText: qsTr("Print receipt")
                                anchors.horizontalCenter: parent.horizontalCenter
                               Image {
                                  id: printReceiptImageId
                                  anchors.fill: parent
                                  source: "qrc:/image/png/Printer64.png"
                               }
                            }
                        }
                     }
                  }
                  Rectangle{
                     color: "transparent"
                     Layout.fillWidth: true
                     Layout.fillHeight: true
                     width: parent.width
                     height: parent.height / 2
                     Row{
                        spacing: 2
//                      layoutDirection: Qt.RightToLeft
                        width: parent.width
                        height: parent.height
                        CommonButton{
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           width: parent.width / 2
                           height: parent.height
                           buttonText: qsTr("EPay")
                           buttonToolTipText: qsTr("Pay by ECart")
                        }
                        CommonButton{
                           Layout.fillWidth: true
                           Layout.fillHeight: true
                           width: parent.width / 2
                           height: parent.height
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
