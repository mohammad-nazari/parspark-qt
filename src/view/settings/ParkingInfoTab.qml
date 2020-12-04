import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "qrc:/src/view/common"

Column{
   property var parkingSettings: ({})

   id: parkingId
   padding: 10
   spacing: 10
   GroupBox {
      title: qsTr("Parking Information")
      Column{
         spacing: 5
         CommonTextField {
            id: parkingNameTextFieldId
            labelText: qsTr("Parking Name:")
            labelWidth: 100
            placeholderTextText:qsTr("Input parking name")
            textFieldWidth: 480
            textFieldText: parkingSettings.parkingName
            onTextFieldTextChanged: {parkingSettings.parkingName = textFieldText}
            textFieldValdator: RegExpValidator { regExp: /^[0-9A-F]{5,20}$/ }
         }
         CommonSpinBox {
            id: parkingCapacitySpinBoxId
            labelText: qsTr("Parking Capacity:")
            labelWidth: 100
            minimumValueValue: 1
            maximumValueValue: 99999
            spinBoxValue: parkingSettings.capacity
            onSpinBoxValueChanged: {parkingSettings.capacity = spinBoxValue}
         }
      }
   }
   GroupBox {
      title: qsTr("Day Tariff")
      Row{
         spacing: 5
         CommonNumericComboBox {
            id: dayFromComboBoxId
            labelText: qsTr("From(Hour):")
            labelWidth: 75
            maximumValue: 23
            comboBoxCurrentValue: parkingSettings.dayTariff.fromHour
            onComboBoxCurrentIndexChanged: {
               nightToComboBoxId.comboBoxCurrentIndex = comboBoxCurrentIndex
               parkingSettings.dayTariff.fromHour = comboBoxCurrentValue
               parkingSettings.nightTariff.toHour = comboBoxCurrentValue
            }
         }
         CommonNumericComboBox {
            id: dayToComboBoxId
            enabled: false
            labelText: qsTr("To(Hour):")
            labelWidth: 50
            maximumValue: 23
            comboBoxCurrentValue: parkingSettings.dayTariff.toHour
         }
         CommonSpinBox{
            labelText: qsTr("First Hour(Tomans):")
            labelWidth: 110
            id: dayFirstHoureSpinBoxId
            minimumValueValue: 0
            maximumValueValue: 999999
            spinBoxValue: parkingSettings.dayTariff.firstHour
            onSpinBoxValueChanged: {parkingSettings.dayTariff.firstHour = spinBoxValue}
         }
         CommonSpinBox{
            id: dayNextHoursSpinBoxId
            labelText: qsTr("Next Hours(Tomans):")
            labelWidth: 110
            minimumValueValue: 0
            maximumValueValue: 999999
            spinBoxValue: parkingSettings.dayTariff.nextHour
            onSpinBoxValueChanged: {parkingSettings.dayTariff.nextHour = spinBoxValue}
         }
      }
   }
   GroupBox {
      title: qsTr("Night Tariff")
      Row{
         spacing: 5
         CommonNumericComboBox {
            id: nightFromComboBoxId
            labelText: qsTr("From(Hour):")
            labelWidth: 75
            maximumValue: 23
            comboBoxCurrentValue: parkingSettings.nightTariff.fromHour
            onComboBoxCurrentIndexChanged: {
               dayToComboBoxId.comboBoxCurrentIndex = comboBoxCurrentIndex
               parkingSettings.nightTariff.fromHour = comboBoxCurrentValue
               parkingSettings.dayTariff.toHour = comboBoxCurrentValue
            }
         }
         CommonNumericComboBox {
            id: nightToComboBoxId
            enabled: false
            labelText: qsTr("To(Hour):")
            labelWidth: 50
            maximumValue: 23
            comboBoxCurrentValue: parkingSettings.nightTariff.toHour
         }
         CommonSpinBox{
            labelText: qsTr("First Hour(Tomans):")
            labelWidth: 110
            id: nightFirstHoureSpinBoxId
            minimumValueValue: 0
            maximumValueValue: 999999
            spinBoxValue: parkingSettings.nightTariff.firstHour
            onSpinBoxValueChanged: {parkingSettings.nightTariff.firstHour = spinBoxValue}
         }
         CommonSpinBox{
            id: nightNextHoursSpinBoxId
            labelText: qsTr("Next Hours(Tomans):")
            labelWidth: 110
            minimumValueValue: 0
            maximumValueValue: 999999
            spinBoxValue: parkingSettings.nightTariff.nextHour
            onSpinBoxValueChanged: {parkingSettings.nightTariff.nextHour = spinBoxValue}
         }
      }
   }
   GroupBox {
      title: qsTr("Daily Tariff")
      CommonSpinBox{
         id: dailySpinBoxId
         labelText: qsTr("Daily(Tomans):")
         labelWidth: 100
         minimumValueValue: 0
         maximumValueValue: 999999
         spinBoxValue: parkingSettings.aDayTariff
         onSpinBoxValueChanged: {parkingSettings.aDayTariff = spinBoxValue}
      }
   }
   GroupBox {
      title: qsTr("Free Times")
      Row{
         spacing: 5
         CommonNumericComboBox {
            id: freeTimeComboBoxId
            labelText: qsTr("Free Time(Minutes):")
            labelWidth: 100
            maximumValue: 120
            comboBoxCurrentValue: parkingSettings.freeTime
            onComboBoxCurrentValueChanged: {parkingSettings.freeTime = comboBoxCurrentValue}
         }
         CommonNumericComboBox {
            id: lastHourFreeTimeComboBoxId
            labelText: qsTr("Last Hour Free Time(Minutes):")
            labelWidth: 150
            maximumValue: 15
            comboBoxCurrentValue: parkingSettings.lastHourFreeTime
            onComboBoxCurrentValueChanged: {parkingSettings.lastHourFreeTime = comboBoxCurrentValue}
         }
      }
   }
}
