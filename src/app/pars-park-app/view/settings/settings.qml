import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13
import QtQuick.Dialogs 1.3
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View 1.0

ApplicationWindow  {
   property var settingsInfo: {
      SettingApi.loadSettings()
      return SettingApi.settingsInfo
   }
   property bool closing: false

//   SettingApi{
//      id: SettingApi
//      objectName: "SettingApi"
//   }
   MessageDialog {
      id: messageDialog
      icon: StandardIcon.Critical
      onAccepted: settingWindowId.close()
   }
   function saveSettings(){
      SettingApi.saveSettings(settingsInfo)
      if(SettingApi.done){
         // Any error in save database settings in file
         if(SettingApi.error.length > 0){
            messageDialog.text = SettingApi.error;
            messageDialog.title =  qsTr("Error on save settings")
            messageDialog.visible = true;
            messageDialog.icon = StandardIcon.Warning
         }
         else{
            messageDialog.text = qsTr("Settings saved successfully")
            messageDialog.title =  qsTr("Save settings")
            messageDialog.visible = true;
            messageDialog.icon = StandardIcon.Information
         }
      }
      else{
         messageDialog.text = SettingApi.error;
         messageDialog.title =  qsTr("Save settings failed")
         messageDialog.visible = true;
         messageDialog.icon = StandardIcon.Warning
      }
      closing = true;
   }
   onClosing: {
      close.accepted = closing
      onTriggered: if(!closing) saveSettings()
   }

   id: settingWindowId
   visible: true
   width: 640
   height: 480
   minimumWidth: width
   minimumHeight: height
   maximumWidth: minimumWidth
   maximumHeight: minimumHeight
   title: qsTr("Setting")
   modality: Qt.WindowModal
   flags: Qt.Dialog
   ColumnLayout{
      id: middleColumnLayoutId
      spacing: 0
      anchors.fill: parent
      TabBar {
         id: tabBarId
         width: parent.width
         //      LayoutMirroring.enabled: true
         //      LayoutMirroring.childrenInherit: true
         ListModel{
            id: tabBarItemsId
            ListElement{tabButtonName: qsTr("Parking")}
            ListElement{tabButtonName: qsTr("ALPR")}
            ListElement{tabButtonName: qsTr("DataBase")}
            ListElement{tabButtonName: qsTr("Camera")}
            ListElement{tabButtonName: qsTr("printer")}
            ListElement{tabButtonName: qsTr("Card Reader")}
            ListElement{tabButtonName: qsTr("Software")}
            ListElement{tabButtonName: qsTr("Gate")}
            ListElement{tabButtonName: qsTr("Board")}
            ListElement{tabButtonName: qsTr("Payment")}
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
         currentIndex: tabBarId.currentIndex
         ParkingInfoTab{
            parkingSettings: settingsInfo.parking
         }
         ALPRTab{
            alprSettings: settingsInfo.alpr
         }
         DataBaseTab{
            dataBaseSettings: settingsInfo.dataBase
         }
         CameraTab{
            cameraSettings: settingsInfo.camera
         }
         PrinterTab{
            printerSettings: settingsInfo.printer
         }
         CardReaderTab{
            cardReaderSettings: settingsInfo.cardReader
         }
         SoftwareTab{
            softwareSettings: settingsInfo.software
         }
         GateTab{
            gateSettings: settingsInfo.gate
         }
         BoardTab{
            boardSettings: settingsInfo.board
         }
         PaymentTab{
            paymentSettings: settingsInfo.payment
         }
      }
      //        CommonButton{
      //            id: closeButtonId
      //            buttonText: qsTr("Close")
      //            width: settingWindowId.width - 50
      //            activeFocusOnTab : true
      //            onClicked: close()
      //        }
   }
}
