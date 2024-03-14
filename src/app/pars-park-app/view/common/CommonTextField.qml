import QtQuick
import QtQuick.Controls

Row {
   property string labelText: qsTr("Label:")
   property int labelWidth: 100
   property string placeholderTextText: qsTr("")
   property int textFieldWidth: 200
   property string textFieldText: qsTr("")
   property int textFieldEchoMode: TextInput.Normal
   property var textFieldValidator: RegularExpressionValidator {}
   property string imageSourceTrue: qsTr("qrc:/image/png/hotovo.png")
   property string imageSourceFalse: qsTr("qrc:/image/png/check.png")

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
      validator: textFieldValidator
   }
   Image {
      id: platePictureImageId
      width: labelId.height
      height: labelId.height
      source: textFieldId.acceptableInput ? imageSourceTrue : imageSourceFalse
   }
}