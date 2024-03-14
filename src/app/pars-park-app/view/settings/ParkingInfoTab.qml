import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "qrc:/src/app/pars-park-app/view/common"

import ANAR.ParsPark.View

Column {
    property var parkingSettings: ({})

    id: parkingId
    padding: 10
    spacing: 10
    GroupBox {
        title: qsTr("Parking Information")
        Column {
            spacing: 5
            CommonTextField {
                id: parkingNameTextFieldId
                labelText: qsTr("Parking Name:")
                labelWidth: 100
                placeholderTextText: qsTr("Input parking name")
                textFieldWidth: 480
                textFieldText: parkingSettings.ParkingName
                onTextFieldTextChanged: {parkingSettings.ParkingName = textFieldText}
                // textFieldValidator: RegExpValidator {
                //     regExp: /^[0-9A-F]{5,20}$/
                // }
            }
            CommonSpinBox {
                id: parkingCapacitySpinBoxId
                labelText: qsTr("Parking Capacity:")
                labelWidth: 100
                minimumValueValue: 1
                maximumValueValue: 99999
                spinBoxValue: parkingSettings.Capacity
                onSpinBoxValueChanged: {parkingSettings.Capacity = spinBoxValue}
            }
        }
    }
    GroupBox {
        title: qsTr("Day Tariff")
        Row {
            spacing: 5
            CommonNumericComboBox {
                id: dayFromComboBoxId
                labelText: qsTr("From(Hour):")
                labelWidth: 75
                maximumValue: 23
                comboBoxCurrentValue: parkingSettings.DayTariff.fromHour
                onComboBoxCurrentIndexChanged: {
                    nightToComboBoxId.comboBoxCurrentIndex = comboBoxCurrentIndex
                    parkingSettings.DayTariff.fromHour = comboBoxCurrentValue
                    parkingSettings.NightTariff.toHour = comboBoxCurrentValue
                }
            }
            CommonNumericComboBox {
                id: dayToComboBoxId
                enabled: false
                labelText: qsTr("To(Hour):")
                labelWidth: 50
                maximumValue: 23
                comboBoxCurrentValue: parkingSettings.DayTariff.toHour
            }
            CommonSpinBox {
                labelText: qsTr("First Hour(Tomans):")
                labelWidth: 110
                id: dayFirstHourSpinBoxId
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: parkingSettings.DayTariff.FirstHour
                onSpinBoxValueChanged: {parkingSettings.DayTariff.FirstHour = spinBoxValue}
            }
            CommonSpinBox {
                id: dayNextHoursSpinBoxId
                labelText: qsTr("Next Hours(Tomans):")
                labelWidth: 110
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: parkingSettings.DayTariff.NextHour
                onSpinBoxValueChanged: {parkingSettings.DayTariff.NextHour = spinBoxValue}
            }
        }
    }
    GroupBox {
        title: qsTr("Night Tariff")
        Row {
            spacing: 5
            CommonNumericComboBox {
                id: nightFromComboBoxId
                labelText: qsTr("From(Hour):")
                labelWidth: 75
                maximumValue: 23
                comboBoxCurrentValue: parkingSettings.NightTariff.FromHour
                onComboBoxCurrentIndexChanged: {
                    dayToComboBoxId.comboBoxCurrentIndex = comboBoxCurrentIndex
                    parkingSettings.NightTariff.FromHour = comboBoxCurrentValue
                    parkingSettings.DayTariff.ToHour = comboBoxCurrentValue
                }
            }
            CommonNumericComboBox {
                id: nightToComboBoxId
                enabled: false
                labelText: qsTr("To(Hour):")
                labelWidth: 50
                maximumValue: 23
                comboBoxCurrentValue: parkingSettings.NightTariff.ToHour
            }
            CommonSpinBox {
                labelText: qsTr("First Hour(Tomans):")
                labelWidth: 110
                id: nightFirstHourSpinBoxId
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: parkingSettings.NightTariff.FirstHour
                onSpinBoxValueChanged: {parkingSettings.NightTariff.FirstHour = spinBoxValue}
            }
            CommonSpinBox {
                id: nightNextHoursSpinBoxId
                labelText: qsTr("Next Hours(Tomans):")
                labelWidth: 110
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: parkingSettings.NightTariff.NextHour
                onSpinBoxValueChanged: {parkingSettings.NightTariff.NextHour = spinBoxValue}
            }
        }
    }
    GroupBox {
        title: qsTr("Daily Tariff")
        CommonSpinBox {
            id: dailySpinBoxId
            labelText: qsTr("Daily(Tomans):")
            labelWidth: 100
            minimumValueValue: 0
            maximumValueValue: 999999
            spinBoxValue: parkingSettings.EveryDayTariff
            onSpinBoxValueChanged: {parkingSettings.EveryDayTariff = spinBoxValue}
        }
    }
    GroupBox {
        title: qsTr("Free Times")
        Row {
            spacing: 5
            CommonNumericComboBox {
                id: freeTimeComboBoxId
                labelText: qsTr("Free Time(Minutes):")
                labelWidth: 100
                maximumValue: 120
                comboBoxCurrentValue: parkingSettings.FreeTime
                onComboBoxCurrentValueChanged: {parkingSettings.FreeTime = comboBoxCurrentValue}
            }
            CommonNumericComboBox {
                id: lastHourFreeTimeComboBoxId
                labelText: qsTr("Last Hour Free Time(Minutes):")
                labelWidth: 150
                maximumValue: 15
                comboBoxCurrentValue: parkingSettings.LastHourFreeTime
                onComboBoxCurrentValueChanged: {parkingSettings.LastHourFreeTime = comboBoxCurrentValue}
            }
        }
    }
}
