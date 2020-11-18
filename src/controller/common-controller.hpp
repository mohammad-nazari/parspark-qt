#ifndef ANAR_COMMON_CONTROLLER_HPP
#define ANAR_COMMON_CONTROLLER_HPP

#include <vector>

#include "base-controller.hpp"

namespace anar::controller {
   class CommonController;
   using CommonControllerPtr = std::shared_ptr<CommonController>;
   class CommonController : public BaseController {
     public:
      static CommonControllerPtr Create();
      CommonController();

      std::vector<std::string> GetSerialPortListNames();
      std::vector<std::string> GetSerialPortBaudRates();
      std::vector<std::string> GetPrinterListNames();
   };
}  // namespace anar::controller
#endif  // ANAR_COMMON_CONTROLLER_HPP
