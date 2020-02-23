import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 1.4
import "../common"

Row{
   padding: 10
   spacing: 2
   GroupBox {
      title: qsTr("Enter Card Reader")
      CommonCOMPort{
         id: enterCardReaderCompPortId
      }
   }
   GroupBox {
      title: qsTr("Exit Card Reader")
      CommonCOMPort{
         id: exitCardReaderCompPortId
      }
   }
}
