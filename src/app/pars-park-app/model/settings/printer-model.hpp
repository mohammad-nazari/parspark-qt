#ifndef ANAR_PARS_PARK_MODEL_PRINTER_HPP
#define ANAR_PARS_PARK_MODEL_PRINTER_HPP

#include "anar/model/model.hpp"

namespace anar::parspark::model {
   class PrinterModel;
   using PrinterModelPtr = std::shared_ptr<PrinterModel>;
   class PrinterModel : public anar::model::Model {
     public:
      PrinterModel()
          : anar::model::Model("Printer") {
      }

      bool Enable{false};
      std::string Title{"In the name of GOD"};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_PRINTER_HPP
