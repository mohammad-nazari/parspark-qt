#ifndef ANAR_COMMON_CONTROLLER_HPP
#define ANAR_COMMON_CONTROLLER_HPP

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
#endif  // ANAR_COMMON_CONTROLLER_HPP
