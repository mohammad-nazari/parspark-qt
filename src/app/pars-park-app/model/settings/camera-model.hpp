#ifndef ANAR_PARS_PARK_MODEL_CAMERA_HPP
#define ANAR_PARS_PARK_MODEL_CAMERA_HPP

#include "model/pars-park-model.hpp"

namespace anar::parspark::model {
   class CameraInfoModel;
   using CameraInfoModelPtr = std::shared_ptr<CameraInfoModel>;
   class CameraInfoModel : public ParsParkModel {
     public:
      CameraInfoModel()
          : ParsParkModel("Camera") {
      }
      ~CameraInfoModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      bool Enable{false};
      std::string Address;
   };

   class CameraModel;
   using CameraModelPtr = std::shared_ptr<CameraModel>;
   class CameraModel : public ParsParkModel {
     public:
      CameraModel()
          : ParsParkModel("Camera") {
      }
      ~CameraModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor &modelBindingVisitor) final {
         return modelBindingVisitor.Visit(*this);
      }

      CameraInfoModel EnterCamera;
      CameraInfoModel ExitCamera;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_CAMERA_HPP
