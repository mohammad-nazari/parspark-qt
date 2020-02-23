import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13

ApplicationWindow  {
    property var settings: ({})

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
        anchors.top: tabBarId.bottom
        currentIndex: tabBarId.currentIndex
        ParkingInfoTab{
            parking: settings.parking
        }
        ALPRTab{
        }
        DataBaseTab{
        }
        CameraTab{
        }
        PrinterTab{
        }
        CardReaderTab{
        }
        SoftwareTab{
        }
        GateTab{
        }
        BoardTab{
        }
        PaymentTab{
        }
    }
}
