#ifndef ANAR_PARS_PARK_MODEL_ALPR_HPP
#define ANAR_PARS_PARK_MODEL_ALPR_HPP

#include "anar/model.hpp"

namespace anar::parspark::model {
   class AlprByCameraModel;
   using AlprByCameraModelPtr = std::shared_ptr<AlprByCameraModel>;
   class AlprByCameraModel : public anar::model::Model {
     public:
      AlprByCameraModel()
          : anar::model::Model("AlprByCamera", "Alpr By  Camera") {
      }

      bool Enable{false};
      bool SubmitWithoutEnterPlate{false};
      bool SubmitWithoutExitPlate{false};
   };

   class AlprModel;
   using AlprModelPtr = std::shared_ptr<AlprModel>;
   class AlprModel : public anar::model::Model {
     public:
      AlprModel()
          : anar::model::Model("Alpr", "Alpr") {
      }

      bool Enable{false};
      AlprByCameraModel ByCamera;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_ALPR_HPP
