import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column{
   padding: 10
   spacing: 2
   GroupBox {
      id: printBillGroupBoxId
      title: qsTr("Print Bill")
      checkable: true
      Column{
         padding: 5
         spacing: 5
         CommonTextField {
            id: customTextTextFieldId
            labelWidth: 100
            labelText: qsTr("Custom Text:")
            textFieldWidth: 480
            placeholderTextText: qsTr("Input custom text")
         }
         CommonComboBox{
            id: printersComboBoxId
            labelWidth: 100
            labelText: qsTr("Printers:")
            width: 300
         }
         CommonButton{
            id: testPrinterButtonId
            width: 100
            buttonText: qsTr("Test")
         }
      }
   }
}
