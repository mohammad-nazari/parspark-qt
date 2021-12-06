#ifndef ANAR_PARS_PARK_MODEL_PRINTER_HPP
#define ANAR_PARS_PARK_MODEL_PRINTER_HPP

#include "model/pars-park-model.hpp"

namespace anar::parspark::model {
   class PrinterModel;
   using PrinterModelPtr = std::shared_ptr<PrinterModel>;
   class PrinterModel : public ParsParkModel {
     public:
      PrinterModel()
          : ParsParkModel("Printer") {
      }
      ~PrinterModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      bool Enable{false};
      std::string Title{"In the name of GOD"};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_PRINTER_HPP
