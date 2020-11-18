#ifndef ANAR_SERIAL_PORT_HPP
#define ANAR_SERIAL_PORT_HPP

#include <memory>
#include <vector>

namespace anar::service {
   class SerialPort;
   using SerialPortPtr = std::shared_ptr<SerialPort>;
   class SerialPort {
     public:
      static SerialPortPtr Create();
      SerialPort();

      //      static std::vector<QSerialPortInfo> GetList();
      static std::vector<std::string> GetListNames();
      static std::vector<std::string> GetListSerialNumbers();
      static std::vector<uint32_t> GetListBaudRates();
      static std::vector<std::string> GetListBaudRatesStr();

     private:
      static const std::vector<uint32_t> m_baudRates;
   };
}  // namespace anar::service
#endif  // ANAR_SERIAL_PORT_HPP
