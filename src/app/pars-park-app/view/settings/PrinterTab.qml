import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Column {
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
        label: CheckBox {
            id: printBill
            text: qsTr("Print Bill")
            checked: printerSettings.Enable
            onCheckedChanged: {printerSettings.Enable = checked}
        }
        Column {
            enabled: printBill.checked
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
            CommonComboBox {
                id: printersComboBoxId
                labelWidth: 100
                labelText: qsTr("Printers:")
                comboBoxWidth: 300
                comboBoxModel: printerModel
                comboBoxCurrentText: printerSettings.PrinterName
                onComboBoxCurrentTextChanged: {printerSettings.PrinterName = comboBoxCurrentText}
            }
            CommonButton {
                id: testPrinterButtonId
                width: 100
                buttonText: qsTr("Test")
            }
        }
    }
}
