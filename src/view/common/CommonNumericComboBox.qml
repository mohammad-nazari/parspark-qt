import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4

Row {
   property string labelText: qsTr("Label:")
   property int labelWidth: 100
   property int minimumValue: 0
   property int maximumValue: 0
   property int interval: 1
   property int comboBoxCurrentIndex: 0
   property int comboBoxWidth: 40

   spacing: 2
   Label{
      text: labelText
      width: labelWidth
      padding: 2
   }
   ComboBox {
      function setItems(){
         var items = [];
         for(var i = 0; i <= maximumValue - minimumValue; i += interval)
         {
            items[i] = i + minimumValue;
         }
         return items;
      }

      id: commonNumericComboBoxId
      model: setItems()
      currentIndex: comboBoxCurrentIndex
      width: comboBoxWidth
      onCurrentIndexChanged: {comboBoxCurrentIndex = currentIndex}
   }
}
