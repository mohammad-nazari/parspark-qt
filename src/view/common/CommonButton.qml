import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import ANAR.ParsPark.View

RoundButton {
    property string buttonText: qsTr("Button")
    property string buttonToolTipText: qsTr("")
    property bool isPressed: false
    property string imageSource: qsTr("")
    property string textColor: qsTr("black")
    property int fontSize: 10

    id: buttonId
    Text {
        id: controlText
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: fontSize
        color: textColor
        text: buttonText
    }
    onTextChanged: {buttonText = text}
    radius: 10
    Layout.margins: 1
    activeFocusOnTab: true
    Layout.fillWidth: true
    Layout.fillHeight: true
    Image {
        id: settingsMenuPictureId
        anchors.fill: parent
        source: imageSource
    }
    // It is provided by 180 in 30 relation between width and height
    //   Layout.preferredWidth: parent.width / 2 - 2
    //   Layout.preferredHeight: width / 6
    background: Rectangle {
        id: bgId
        radius: parent.radius
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: hovered ? (isPressed ? "white" : "white") : "lightcyan"
            }
            GradientStop {
                position: 1.00;
                color: hovered ? (isPressed ? "lightblue" : "lightcyan") : "white"
            }
        }
        border {
            width: hovered ? 2 : 1
            color: "lightgray"
        }
    }
    MouseArea {
        id: mouseAreaId
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true
        onPressed: isPressed = true;
        onReleased: isPressed = false
        onClicked: parent.clicked()
    }
    ToolTip {
        text: buttonToolTipText
        timeout: 5000
        visible: hovered && buttonToolTipText !== ""
        background: Rectangle {
            id: bgToolTipId
            radius: 10
            gradient: Gradient {
                GradientStop {
                    position: 0.00;
                    color: "black"
                }
                GradientStop {
                    position: 1.00;
                    color: "darkgray"
                }
            }
        }
    }
}
