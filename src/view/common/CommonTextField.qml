import QtQuick 2.13
import QtQuick.Controls 1.4

Row {
    property string labelText: qsTr("Label:")
    property int labelWidth: 100
    property string placeholderTextText: qsTr("")
    property int textFieldWidth: 200
    property string textFieldText: ""
    property var textFieldEchoMode: TextInput.Normal

    leftPadding: 5
    spacing: 2
    Label{
        id: labelId
        width: labelWidth
        text: labelText
        padding: 2
    }
    TextField{
        id: textFieldId
        width: textFieldWidth
        placeholderText: placeholderTextText
        text: textFieldText
        onTextChanged: {textFieldText = text}
        echoMode: textFieldEchoMode
    }
}
