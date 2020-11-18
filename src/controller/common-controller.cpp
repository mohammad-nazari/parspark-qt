#include "common-controller.hpp"

#include "service/printer.hpp"
#include "service/serial-port.hpp"

namespace anar::controller {
   CommonControllerPtr CommonController::Create() {
      return std::make_shared<CommonController>();
   }
   CommonController::CommonController()
       : BaseController() {
   }

   std::vector<std::string> CommonController::GetSerialPortListNames() {
      return service::SerialPort::GetListNames();
   }
   std::vector<std::string> CommonController::GetSerialPortBaudRates() {
      return service::SerialPort::GetListBaudRatesStr();
   }
   std::vector<std::string> CommonController::GetPrinterListNames() {
      return service::Printer::GetListNames();
   }
}  // namespace anar::controller
