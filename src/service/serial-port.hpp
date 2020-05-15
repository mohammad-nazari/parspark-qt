#ifndef SERVICE_SERIAL_PORT_HPP
#define SERVICE_SERIAL_PORT_HPP

#include <QList>
#include <QSerialPortInfo>
#include <model/settings/settings.hpp>

namespace parspark::service {
   class SerialPort;
   using SerialPortPtr = std::shared_ptr<SerialPort>;
   class SerialPort {
    public:
      static SerialPortPtr Create();
      SerialPort();

      static QList<QSerialPortInfo> GetList();
      static QStringList GetListNames();
      static QStringList GetListSerialNumbers();
   };
} // namespace parspark::service
#endif // SERVICE_SERIAL_PORT_HPP
