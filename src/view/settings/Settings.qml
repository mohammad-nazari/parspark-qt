import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs

import ANAR.ParsPark.View

ApplicationWindow {
    property var settingsInfo: {
        SettingApi.loadSettings()
        return SettingApi.settingsInfo
    }
    property bool closing: false
    MessageDialog {
        id: messageDialog
        buttons: MessageDialog.Ok
        onAccepted: settingWindowId.close()
    }

    function saveSettings() {
        SettingApi.saveSettings(settingsInfo)
        // Any error in save database settings in file
        if (SettingApi.error.length > 0) {
            messageDialog.text = qsTr("Error on saving settings")
            messageDialog.informativeText = SettingApi.error
            messageDialog.visible = true;
        } else {
            messageDialog.text = qsTr("Save settings")
            messageDialog.informativeText = qsTr("Settings were saved successfully")
            messageDialog.visible = true;
        }
        closing = true;
    }

    onClosing: (close) => {
        close.accepted = closing
        if (!settingWindowId.closing) saveSettings()
    }

    id: settingWindowId
    visible: true
    width: 800
    height: 600
    minimumWidth: width
    minimumHeight: height
    maximumWidth: minimumWidth
    maximumHeight: minimumHeight
    title: qsTr("Setting")
    modality: Qt.WindowModal
    flags: Qt.Dialog
    ColumnLayout {
        id: middleColumnLayoutId
        spacing: 0
        anchors.fill: parent
        TabBar {
            id: tabBarId
            width: parent.width
            //      LayoutMirroring.enabled: true
            //      LayoutMirroring.childrenInherit: true
            ListModel {
                id: tabBarItemsId
                ListElement {
                    tabButtonName: qsTr("Parking")
                }
                ListElement {
                    tabButtonName: qsTr("ALPR")
                }
                ListElement {
                    tabButtonName: qsTr("DataBase")
                }
                ListElement {
                    tabButtonName: qsTr("Camera")
                }
                ListElement {
                    tabButtonName: qsTr("printer")
                }
                ListElement {
                    tabButtonName: qsTr("Card Reader")
                }
                ListElement {
                    tabButtonName: qsTr("Software")
                }
                ListElement {
                    tabButtonName: qsTr("Gate")
                }
                ListElement {
                    tabButtonName: qsTr("Board")
                }
                ListElement {
                    tabButtonName: qsTr("Payment")
                }
            }
            Repeater {
                model: tabBarItemsId
                delegate: tabBarItemId
            }
            Component {
                id: tabBarItemId
                TabButton {
                    id: tabButtonId
                    property bool isMouseArea: false
                    text: tabButtonName
                    hoverEnabled: true
                    z: 0
                    MouseArea {
                        id: mouseAreaId
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        hoverEnabled: true
                        onEntered: isMouseArea = true
                        onExited: isMouseArea = false
                        onClicked: tabBarId.currentIndex = model.index
                    }
                    ToolTip {
                        text: tabButtonName
                        timeout: 5000
                        visible: isMouseArea && tabButtonName !== ""
                        background: Rectangle {
                            id: bgToolTipId
                            radius: 10
                            gradient: Gradient {
                                GradientStop {
                                    position: 0.00
                                    color: "black"
                                }
                                GradientStop {
                                    position: 1.00
                                    color: "darkgray"
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
            ParkingInfoTab {
                parkingSettings: settingsInfo.Parking
            }
            ALPRTab {
                alprSettings: settingsInfo.Alpr
            }
            DataBaseTab {
                dataBaseSettings: settingsInfo.DataBase
            }
            CameraTab {
                cameraSettings: settingsInfo.Camera
            }
            PrinterTab {
                printerSettings: settingsInfo.Printer
            }
            CardReaderTab {
                cardReaderSettings: settingsInfo.CardReader
            }
            SoftwareTab {
                softwareSettings: settingsInfo.Software
            }
            GateTab {
                gateSettings: settingsInfo.Gate
            }
            BoardTab {
                boardSettings: settingsInfo.Board
            }
            PaymentTab {
                paymentSettings: settingsInfo.Payment
            }
        }
    }
}
