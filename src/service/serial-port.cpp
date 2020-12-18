#include "serial-port.hpp"

#include "lib/rs232/rs232.h"
#include <string>

namespace anar::service {
   const std::vector<uint32_t> SerialPort::m_baudRates = {
#if defined(__linux__) || defined(__FreeBSD__)
       50,     75,     110,    134,    150,    200,    300,     600,     1200,    1800,    2400,    4800,    9600,    19200,  38400, 57600,
       115200, 230400, 460800, 500000, 576000, 921600, 1000000, 1152000, 1500000, 2000000, 2500000, 3000000, 3500000, 4000000
#else
       110,    300,    600,    1200,   2400,   4800,    9600,    19200,   38400,  57600,
       115200, 128000, 256000, 500000, 921600, 1000000, 1500000, 2000000, 3000000
#endif
   };

   SerialPortPtr SerialPort::Create() {
      return std::make_shared<SerialPort>();
   }
   SerialPort::SerialPort() = default;

   //   std::vector<QSerialPortInfo> SerialPort::GetList() {
   //      return QSerialPortInfo::availablePorts();
   //   }
   std::vector<std::string> SerialPort::GetListNames() {
      std::vector<std::string> serialPortNames;
      //      auto serialPorts = GetList();
      //      for (const auto& serialPort : serialPorts) {
      //         serialPortNames.push_back(serialPort.portName());
      //      }
      return serialPortNames;
   }
   std::vector<std::string> SerialPort::GetListSerialNumbers() {
      std::vector<std::string> serialPortSerialNumber;
      //      auto serialPorts = GetList();
      //      for (const auto& serialPort : serialPorts) {
      //         serialPortSerialNumber.push_back(serialPort.serialNumber());
      //      }
      return serialPortSerialNumber;
   }
   std::vector<uint32_t> SerialPort::GetListBaudRates() {
      return m_baudRates;
   }
   std::vector<std::string> SerialPort::GetListBaudRatesStr() {
      std::vector<std::string> baudRatesStr;
      for (const auto baudRate : m_baudRates) {
         baudRatesStr.push_back(std::to_string(baudRate));
      }
      return baudRatesStr;
   }
}  // namespace anar::service
