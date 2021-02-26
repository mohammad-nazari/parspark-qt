#ifndef ANAR_SERIAL_PORT_HPP
#define ANAR_SERIAL_PORT_HPP

#include <memory>
#include <vector>
#include <serial/serial.h>

namespace anar::service {
   class SerialPort;
   using SerialPortPtr = std::shared_ptr<SerialPort>;
   class SerialPort {
     public:
      static SerialPortPtr Create();
      SerialPort();

      static std::vector<serial::PortInfo> GetSerialPorts();
      static std::vector<std::string> GetSerialPortNames();
      static std::vector<std::string> GetSerialPortNumbers();
      static std::vector<uint32_t> GetSerialPortBaudRates();
      static std::vector<std::string> GetSerialPortBaudRatesStr();

     private:
      static const std::vector<uint32_t> m_baudRates;
   };
}  // namespace anar::service
#endif  // ANAR_SERIAL_PORT_HPP
