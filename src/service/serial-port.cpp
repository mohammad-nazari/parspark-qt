#include "serial-port.hpp"
#include <QtDebug>

namespace parspark::service {
   SerialPortPtr SerialPort::Create() {
      return std::make_shared<SerialPort>();
   }

   SerialPort::SerialPort() {
   }

   QList<QSerialPortInfo> SerialPort::GetList() {
      return QSerialPortInfo::availablePorts();
   }

   QStringList SerialPort::GetListNames() {
      QList<QString> serialPortNames;
      auto serialPorts = GetList();
      for (const auto serialPort : serialPorts) {
         serialPortNames.push_back(serialPort.portName());
      }
      return serialPortNames;
   }

   QStringList SerialPort::GetListSerialNumbers() {
      QList<QString> serialPortSerialNumber;
      auto serialPorts = GetList();
      for (const auto serialPort : serialPorts) {
         serialPortSerialNumber.push_back(serialPort.serialNumber());
      }
      return serialPortSerialNumber;
   }
} // namespace parspark::service
