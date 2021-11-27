#include "anar/serial-port.hpp"

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

   std::vector<serial::PortInfo> SerialPort::GetSerialPorts() {
      return serial::list_ports();
   }
   std::vector<std::string> SerialPort::GetSerialPortNames() {
      std::vector<std::string> serialPortNames;
      auto serialPorts = GetSerialPorts();
      serialPortNames.reserve(serialPorts.size());
      for (const auto& serialPort : serialPorts) {
         serialPortNames.emplace_back(serialPort.description);
      }
      return serialPortNames;
   }
   std::vector<std::string> SerialPort::GetSerialPortNumbers() {
      std::vector<std::string> serialPortSerialNumber;
      auto serialPorts = GetSerialPorts();
      serialPortSerialNumber.reserve(serialPorts.size());
      for (const auto& serialPort : serialPorts) {
         serialPortSerialNumber.push_back(serialPort.port);
      }
      return serialPortSerialNumber;
   }
   std::vector<uint32_t> SerialPort::GetSerialPortBaudRates() {
      return m_baudRates;
   }
   std::vector<std::string> SerialPort::GetSerialPortBaudRatesStr() {
      std::vector<std::string> baudRatesStr;
      baudRatesStr.reserve(m_baudRates.size());
      for (const auto& baudRate : m_baudRates) {
         baudRatesStr.push_back(std::to_string(baudRate));
      }
      return baudRatesStr;
   }
}  // namespace anar::service
