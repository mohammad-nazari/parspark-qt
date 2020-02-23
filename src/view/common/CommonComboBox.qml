import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Row {
   property var comboBoxModel: []
   property string labelText: qsTr("Label:")
   property int labelWidth: 100
   property int comboBoxCurrentIndex: 0
   property int comboBoxWidth: 120

   spacing: 2
   Label{
      text: labelText
      width: labelWidth
      padding: 2
   }
   ComboBox {
      id: commonNumericComboBoxId
      model: comboBoxModel
      currentIndex: comboBoxCurrentIndex
      onCurrentIndexChanged: {comboBoxCurrentIndex = currentIndex}
      width: comboBoxWidth
   }
}
