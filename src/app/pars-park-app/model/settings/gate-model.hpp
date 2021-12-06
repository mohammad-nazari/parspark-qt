#ifndef ANAR_PARS_PARK_MODEL_GATE_HPP
#define ANAR_PARS_PARK_MODEL_GATE_HPP

#include "comport-model.hpp"

namespace anar::parspark::model {
   class GateInfoModel;
   using GateInfoModelPtr = std::shared_ptr<GateInfoModel>;
   class GateInfoModel : public ParsParkModel {
     public:
      GateInfoModel()
          : ParsParkModel("Gate") {
      }
      ~GateInfoModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      bool Enable{false};
      ComPortModel Address;
      bool OpenAuto{true};
      bool CloseAuto{true};
      uint16_t CloseAfter{15};
   };

   class GateModel;
   using GateModelPtr = std::shared_ptr<GateModel>;
   class GateModel : public ParsParkModel {
     public:
      GateModel()
          : ParsParkModel("Gate") {
      }
      ~GateModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      GateInfoModel Enter;
      GateInfoModel Exit;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_GATE_HPP
