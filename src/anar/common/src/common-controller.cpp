#include "anar/common-controller.hpp"

#include "anar/printer.hpp"
#include "anar/serial-port.hpp"

namespace anar::common::controller {
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
}  // namespace anar::common::controller
