import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Row {
   property var comboBoxModel: []
   property string labelText: qsTr("Label:")
   property int labelWidth: 100
   property int minimumValue: 0
   property int maximumValue: 0
   property int interval: 1
   property int comboBoxCurrentIndex: -1
   property int comboBoxCurrentValue
   property int comboBoxWidth: 40

   Component.onCompleted: {
       comboBoxCurrentIndex = comboBoxModel.indexOf(comboBoxCurrentValue);
   }

   spacing: 2
   Label{
      text: labelText
      width: labelWidth
      padding: 2
   }
   ComboBox {
      function setItems(){
         comboBoxModel = [];
         for(var i = minimumValue; i <= maximumValue ; i += interval)
         {
            comboBoxModel[i - minimumValue] = i;
         }
         return comboBoxModel;
      }

      id: commonNumericComboBoxId
      width: comboBoxWidth
      model: setItems()
      currentIndex: comboBoxCurrentIndex
      onCurrentIndexChanged: {
         comboBoxCurrentValue = comboBoxModel.length > 0 ? comboBoxModel[currentIndex]: 0
         comboBoxCurrentIndex = currentIndex
      }
   }
}
