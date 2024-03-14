import QtQuick
import QtQuick.Layouts

Rectangle {
    property string imageSource: qsTr("qrc:/image/png/car2.png")

    id: platePictureRectangleId
    color: "transparent"
    border{
        color: "black"
        width: 1
    }
    radius: 10
    Layout.margins: 2
    Layout.fillWidth: true
    Layout.fillHeight: true
    // It is provide by a full HD resolution image size relation (1980 in 1080)
    width: parent.width
    height: width * 9 / 16
    Image {
        id: platePictureImageId
        anchors.fill: parent
        source: imageSource
    }
}
