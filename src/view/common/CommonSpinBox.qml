import QtQuick 2.13
import QtQuick.Controls 1.4

Row {
   property string labelText: qsTr("Label:")
   property int labelWidth: 100
   property int minimumValueValue: 0
   property int maximumValueValue: 99
   property int spinBoxValue: 0

   leftPadding: 5
   spacing: 2
   Label{
      text: labelText
      width: labelWidth
      padding: 2
   }
   SpinBox{
      id: serverPortNumberSpinBoxId
      minimumValue: minimumValueValue
      maximumValue: maximumValueValue
      value: spinBoxValue
      onValueChanged: {spinBoxValue = value}
   }
}
