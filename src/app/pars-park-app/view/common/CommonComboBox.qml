import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Row {
   property var comboBoxModel: []
   property string labelText: qsTr("Label:")
   property int labelWidth: 100
   property int comboBoxCurrentIndex: -1
   property string comboBoxCurrentText: ""
   property int comboBoxWidth: 150

   spacing: 2
   Label{
      text: labelText
      width: labelWidth
      padding: 2
   }
   ComboBox {
      id: commonNumericComboBoxId
      width: comboBoxWidth
      model: comboBoxModel
      currentIndex: comboBoxModel.indexOf(comboBoxCurrentText)
      onCurrentIndexChanged: {
         comboBoxCurrentIndex = currentIndex
         comboBoxCurrentText = comboBoxModel && comboBoxModel.length > 0 ? comboBoxModel[currentIndex]: ""
      }
   }
}
