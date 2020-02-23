import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Column{
    property var parking: ({})
    id: parkingColumnId
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
                textFieldWidth: 500
                textFieldText: parking && parking.name ?  parking.name : "New Parking"
            }
            CommonSpinBox {
                id: parkingCapacitySpinBoxId
                labelText: qsTr("Parking Capacity:")
                labelWidth: 100
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: parking && parking.capacity ? parking.capacity : 100
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
                comboBoxCurrentIndex: 7
                onComboBoxCurrentIndexChanged: {
                    nightToComboBoxId.comboBoxCurrentIndex = comboBoxCurrentIndex
                }
            }
            CommonNumericComboBox {
                id: dayToComboBoxId
                enabled: false
                labelText: qsTr("To(Hour):")
                labelWidth: 50
                maximumValue: 23
                comboBoxCurrentIndex: nightFromComboBoxId.comboBoxCurrentIndex
            }
            CommonSpinBox{
                labelText: qsTr("First Hour(Tomans):")
                labelWidth: 100
                id: dayFirstHoureSpinBoxId
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: 1800
            }
            CommonSpinBox{
                id: dayNextHoursSpinBoxId
                labelText: qsTr("Next Hours(Tomans):")
                labelWidth: 100
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: 2400
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
                comboBoxCurrentIndex: 22
                onComboBoxCurrentIndexChanged: {
                    dayToComboBoxId.comboBoxCurrentIndex = comboBoxCurrentIndex
                }
            }
            CommonNumericComboBox {
                id: nightToComboBoxId
                enabled: false
                labelText: qsTr("To(Hour):")
                labelWidth: 50
                maximumValue: 23
                comboBoxCurrentIndex: dayFromComboBoxId.comboBoxCurrentIndex
            }
            CommonSpinBox{
                labelText: qsTr("First Hour(Tomans):")
                labelWidth: 100
                id: nightFirstHoureSpinBoxId
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: 2400
            }
            CommonSpinBox{
                id: nightNextHoursSpinBoxId
                labelText: qsTr("Next Hours(Tomans):")
                labelWidth: 100
                minimumValueValue: 0
                maximumValueValue: 999999
                spinBoxValue: 3000
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
            spinBoxValue: 0
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
                comboBoxCurrentIndex: 0
            }
            CommonNumericComboBox {
                id: lastHourFreeTimeComboBoxId
                labelText: qsTr("Last Hour Free Time(Minutes):")
                labelWidth: 150
                maximumValue: 15
                comboBoxCurrentIndex: 0
            }
        }
    }
}
