#ifndef ANAR_CONTROLLER_COMMON_HPP
#define ANAR_CONTROLLER_COMMON_HPP

#include <vector>

#include "controller.hpp"

namespace anar::controller {
   class CommonController;
   using CommonControllerPtr = std::shared_ptr<CommonController>;
   class CommonController : public Controller {
     public:
      static CommonControllerPtr Create();
      CommonController();

      static std::vector<std::string> GetSerialPortListNames();
      static std::vector<std::string> GetSerialPortBaudRates();
      static std::vector<std::string> GetPrinterListNames();
   };
}  // namespace anar::controller
#endif  // ANAR_CONTROLLER_COMMON_HPP
