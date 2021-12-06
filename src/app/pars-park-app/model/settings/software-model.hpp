#ifndef ANAR_PARS_PARK_MODEL_SOFTWARE_HPP
#define ANAR_PARS_PARK_MODEL_SOFTWARE_HPP

#include "server-model.hpp"

namespace anar::parspark::model {
   class SoftwareModel;
   using SoftwareModelPtr = std::shared_ptr<SoftwareModel>;
   class SoftwareModel : public ParsParkModel {
     public:
      SoftwareModel()
          : ParsParkModel("Software") {
      }
      ~SoftwareModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      bool ActiveEnter{false};
      bool ActiveExit{false};
      bool IsServer{true};
      uint16_t Port{50001};
      ServerModel ServerAddress;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_SOFTWARE_HPP
