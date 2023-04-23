#ifndef ANAR_PARS_PARK_MODEL_ALPR_HPP
#define ANAR_PARS_PARK_MODEL_ALPR_HPP

#include "model/pars-park-model.hpp"

namespace anar::parspark::model {
   class AlprByCameraModel;
   using AlprByCameraModelPtr = std::shared_ptr<AlprByCameraModel>;
   class AlprByCameraModel : public ParsParkModel {
     public:
      AlprByCameraModel()
          : ParsParkModel("AlprByCamera", "Alpr By  Camera") {
      }
      ~AlprByCameraModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      bool Enable{false};
      bool SubmitWithoutEnterPlate{false};
      bool SubmitWithoutExitPlate{false};
   };

   class AlprModel;
   using AlprModelPtr = std::shared_ptr<AlprModel>;
   class AlprModel : public ParsParkModel {
     public:
      AlprModel()
          : ParsParkModel("Alpr", "Alpr") {
      }
      ~AlprModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      bool Enable{false};
      AlprByCameraModel ByCamera;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_ALPR_HPP
