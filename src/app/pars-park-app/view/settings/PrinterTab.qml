import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View 1.0

Column{
   property var printerSettings: ({})
   property var printerModel: {
      CommonApi.getPrinters();
      return CommonApi.printers;
   }
//   CommonApi{
//      id: commonApi;
//   }

   id: printerId
   padding: 10
   spacing: 2
   GroupBox {
      id: printBillGroupBoxId
      title: qsTr("Print Bill")
      checkable: true
      checked: printerSettings.Enable
      onCheckedChanged: {printerSettings.Enable = checked}
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            id: customTextTextFieldId
            labelWidth: 100
            labelText: qsTr("Custom Text:")
            textFieldWidth: 480
            placeholderTextText: qsTr("Input custom text")
            textFieldText: printerSettings.Title
            onTextFieldTextChanged: {printerSettings.Title = textFieldText}
         }
         CommonComboBox{
            id: printersComboBoxId
            labelWidth: 100
            labelText: qsTr("Printers:")
            comboBoxWidth: 300
            comboBoxModel: printerModel
            comboBoxCurrentText: printerSettings.PrinterName
            onComboBoxCurrentTextChanged: {printerSettings.PrinterName = comboBoxCurrentText}
         }
         CommonButton{
            id: testPrinterButtonId
            width: 100
            buttonText: qsTr("Test")
         }
      }
   }
}
