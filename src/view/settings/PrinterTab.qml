import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/view/common"

import ParsPark.View 1.0

Column{
   property var printerSettings: ({})
   property var printerModel: {
      commonApi.getPrinters();
      return commonApi.printers;
   }
   CommonApi{
      id: commonApi;
   }

   id: printerId
   padding: 10
   spacing: 2
   GroupBox {
      id: printBillGroupBoxId
      title: qsTr("Print Bill")
      checkable: true
      checked: printerSettings.enable
      onCheckedChanged: {printerSettings.enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            id: customTextTextFieldId
            labelWidth: 100
            labelText: qsTr("Custom Text:")
            textFieldWidth: 480
            placeholderTextText: qsTr("Input custom text")
            textFieldText: printerSettings.title
            onTextFieldTextChanged: {printerSettings.title = textFieldText}
         }
         CommonComboBox{
            id: printersComboBoxId
            labelWidth: 100
            labelText: qsTr("Printers:")
            comboBoxWidth: 300
            comboBoxModel: printerModel
            comboBoxCurrentText: printerSettings.name
            onComboBoxCurrentTextChanged: {printerSettings.name = comboBoxCurrentText}
         }
         CommonButton{
            id: testPrinterButtonId
            width: 100
            buttonText: qsTr("Test")
         }
      }
   }
}
