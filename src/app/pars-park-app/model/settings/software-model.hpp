#ifndef ANAR_PARS_PARK_MODEL_SOFTWARE_HPP
#define ANAR_PARS_PARK_MODEL_SOFTWARE_HPP

#include "server-model.hpp"

namespace anar::parspark::model {
   class SoftwareModel;
   using SoftwareModelPtr = std::shared_ptr<SoftwareModel>;
   class SoftwareModel : public anar::model::Model {
     public:
      SoftwareModel()
          : anar::model::Model("Software") {
      }

      bool ActiveEnter{false};
      bool ActiveExit{false};
      bool IsServer{true};
      uint16_t Port{50001};
      ServerModel ServerAddress;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_SOFTWARE_HPP
