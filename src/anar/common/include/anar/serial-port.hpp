#ifndef ANAR_SERVICE_SERIAL_PORT_HPP
#define ANAR_SERVICE_SERIAL_PORT_HPP

#include <serial/serial.h>

#include <memory>
#include <vector>

namespace anar::common::service {
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
}  // namespace anar::common::service
#endif  // ANAR_SERVICE_SERIAL_PORT_HPP
