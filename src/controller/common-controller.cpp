#include "common-controller.hpp"

#include "service/printer.hpp"
#include "service/serial-port.hpp"

namespace anar::controller {
   CommonControllerPtr CommonController::Create() {
      return std::make_shared<CommonController>();
   }
   CommonController::CommonController()
       : Controller() {
   }

   std::vector<std::string> CommonController::GetSerialPortListNames() {
      return service::SerialPort::GetSerialPortNames();
   }
   std::vector<std::string> CommonController::GetSerialPortBaudRates() {
      return service::SerialPort::GetSerialPortBaudRatesStr();
   }
   std::vector<std::string> CommonController::GetPrinterListNames() {
      return service::Printer::GetListNames();
   }
}  // namespace anar::controller
