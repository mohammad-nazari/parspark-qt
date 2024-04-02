import QtQuick
import QtQuick.Controls

import ANAR.ParsPark.View

Column {
   property var comPortModel:  {
      CommonApi.getSerialPorts()
      return CommonApi.serialPorts
   }
   property var baudRateModel: {
      CommonApi.getSerialPortBaudRates()
      return CommonApi.baudRates
   }
//       ["110", "300", "600", "1200", "2400", "4800", "9600", "14400", "19200", "28800", "38400", "56000", "57600", "115200"]
   property string address: qsTr("")
   property int baudRate: 19200

//   CommonApi{
//      id: CommonApi
//   }

   padding: 5
   spacing: 5
   CommonComboBox{
      id: comPortNameComboBoxId
      labelText: qsTr("COM port name:")
      labelWidth: 100
      comboBoxModel: comPortModel
      comboBoxWidth: 120
      comboBoxCurrentText: address
      onComboBoxCurrentTextChanged: { address = comboBoxCurrentText}
   }
   CommonComboBox{
      id: baudRateComboBoxId
      labelText: qsTr("Baud rate:")
      labelWidth: 100
      comboBoxModel: baudRateModel
      comboBoxWidth: 120
      width: 120
      comboBoxCurrentText: baudRate
      onComboBoxCurrentTextChanged: {baudRate = comboBoxCurrentText}
   }
   CommonButton{
      id: testButtonId
      spacing: 5
      width: 100
      buttonText: qsTr("Test")
   }
}
