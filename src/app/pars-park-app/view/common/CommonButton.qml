import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

RoundButton {
    property string buttonText: qsTr("Button")
    property string buttonToolTipText: qsTr("")
    property bool isMouseArea: false
    property bool isPressed: false
    property string imageSource: qsTr("")
    property int fontSize: 10

    id: buttonId
    Text {
        id: controlText
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: fontSize
        color: "black"
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
                color: isMouseArea ? (isPressed ? "white" : "white") : "lightcyan"
            }
            GradientStop {
                position: 1.00;
                color: isMouseArea ? (isPressed ? "lightblue" : "lightcyan") : "white"
            }
        }
        border {
            width: isMouseArea ? 2 : 1
            color: "lightgray"
        }
    }
    MouseArea {
        id: mouseAreaId
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true
        onEntered: isMouseArea = true
        onExited: isMouseArea = false
        onPressed: isPressed = true;
        onReleased: isPressed = false
        onClicked: parent.clicked()
    }
    ToolTip {
        text: buttonToolTipText
        timeout: 5000
        visible: isMouseArea && buttonToolTipText !== ""
        background: Rectangle {
            id: bgToolTipId
            radius: 10
            gradient: Gradient {
                GradientStop {
                    position: 0.00;
                    color: "white"
                }
                GradientStop {
                    position: 1.00;
                    color: "lightcyan"
                }
            }
        }
    }
}
