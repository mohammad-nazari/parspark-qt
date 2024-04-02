#ifndef ANAR_PARS_PARK_MODEL_COMPORT_HPP
#define ANAR_PARS_PARK_MODEL_COMPORT_HPP

#include "model/pars-park-model.hpp"

namespace anar::parspark::model {
   class ComPortModel;
   using ComPortModelPtr = std::shared_ptr<ComPortModel>;
   class ComPortModel : public ParsParkModel {
     public:
      ComPortModel()
          : ParsParkModel("Comport", "Comport") {
      }
      ~ComPortModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      std::string PortName;
      uint32_t BaudRate{19200};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_COMPORT_HPP
