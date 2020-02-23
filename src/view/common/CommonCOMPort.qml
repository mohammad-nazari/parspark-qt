import QtQuick 2.13
import QtQuick.Controls 1.4

Column {
    property var comPortModel: []
    property string address: ""
    property int baudRate: 19200

    padding: 5
    spacing: 5
    CommonComboBox{
        id: comPortNameComboBoxId
        labelText: qsTr("COM port name:")
        labelWidth: 100
        comboBoxModel: comPortModel
        comboBoxWidth: 120
        onComboBoxCurrentIndexChanged: { address = comboBoxModel[comboBoxCurrentIndex]}
    }
    CommonComboBox{
        id: baudRateComboBoxId
        labelText: qsTr("Baud rate:")
        labelWidth: 100
        comboBoxModel:  [110, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 38400, 56000, 57600, 115200]
        comboBoxWidth: 120
        width: 120
        comboBoxCurrentIndex: 8
        onComboBoxCurrentIndexChanged: {baudRate = comboBoxModel[comboBoxCurrentIndex]}
    }
    CommonButton{
        id: testButtonId
        spacing: 5
        width: 100
        buttonText: qsTr("Test")
    }
}
