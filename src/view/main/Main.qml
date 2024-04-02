import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs

import ANAR.ParsPark.View

ApplicationWindow {
    id: mainApplicationWindowId
    property real relativeSize: 1.333334
    property var settings: ({})
    property bool closing: false

    MessageDialog {
        id: exitMessageDialogId
        // icon: StandardIcon.Question
        text: qsTr("Click to exit.")
        informativeText: qsTr("Are you sure to exit?")
        buttons: MessageDialog.Yes | MessageDialog.No
        onAccepted: {
            mainApplicationWindowId.closing = true
            mainApplicationWindowId.close()
        }
    }
    onClosing: (close) => {
        close.accepted = mainApplicationWindowId.closing
        if (!mainApplicationWindowId.closing) exitMessageDialogId.open()
    }

    visible: true
    width: 800
    height: 600
    minimumWidth: 800
    minimumHeight: 600
    title: qsTr("ParsPark")
    Rectangle {
        id: bgId
        anchors.fill: parent
        color: "transparent"
        MainColumnLayout {
            id: columnLayoutId
            // anchors.bottomMargin: statusBarId.height
        }
    }
    // StatusBar {
    //     id: statusBarId
    //     anchors.bottom: parent.bottom
    //     RowLayout {
    //         CommonDigitalClock {
    //             id: digitalClockId
    //         }
    //     }
    // }
}
