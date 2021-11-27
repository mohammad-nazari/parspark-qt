#ifndef ANAR_PARS_PARK_MODEL_CAMERA_HPP
#define ANAR_PARS_PARK_MODEL_CAMERA_HPP

#include "anar/model.hpp"

namespace anar::parspark::model {
   class CameraInfoModel;
   using CameraInfoModelPtr = std::shared_ptr<CameraInfoModel>;
   class CameraInfoModel : public anar::model::Model {
     public:
      CameraInfoModel()
          : anar::model::Model("Camera") {
      }

      bool Enable{false};
      std::string Address;
   };

   class CameraModel;
   using CameraModelPtr = std::shared_ptr<CameraModel>;
   class CameraModel : public anar::model::Model {
     public:
      CameraModel()
          : anar::model::Model("Camera") {
      }

      CameraInfoModel Enter;
      CameraInfoModel Exit;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_CAMERA_HPP
