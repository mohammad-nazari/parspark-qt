#ifndef ANAR_PARS_PARK_MODEL_GATE_HPP
#define ANAR_PARS_PARK_MODEL_GATE_HPP

#include "comport-model.hpp"

namespace anar::parspark::model {
   class GateInfoModel;
   using GateInfoModelPtr = std::shared_ptr<GateInfoModel>;
   class GateInfoModel : public anar::model::Model {
     public:
      GateInfoModel()
          : anar::model::Model("Gate") {
      }

      bool Enable{false};
      ComPortModel Address;
      bool OpenAuto{true};
      bool CloseAuto{true};
      uint16_t CloseAfter{15};
   };

   class GateModel;
   using GateModelPtr = std::shared_ptr<GateModel>;
   class GateModel : public anar::model::Model {
     public:
      GateModel()
          : anar::model::Model("Gate") {
      }

      GateInfoModel Enter;
      GateInfoModel Exit;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_GATE_HPP
