#ifndef ANAR_PARS_PARK_MODEL_COMPORT_HPP
#define ANAR_PARS_PARK_MODEL_COMPORT_HPP

#include "anar/model.hpp"

namespace anar::parspark::model {
   class ComPortModel;
   using ComPortModelPtr = std::shared_ptr<ComPortModel>;
   class ComPortModel : public anar::model::Model {
     public:
      ComPortModel()
          : anar::model::Model("Comport", "Comport") {
      }

      std::string PortName;
      uint16_t BaudRate{19200};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_COMPORT_HPP
