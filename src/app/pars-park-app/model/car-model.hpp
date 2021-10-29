#ifndef ANAR_CAR_MODEL_HPP
#define ANAR_CAR_MODEL_HPP

#include "driver-model.hpp"

namespace anar {
   namespace model {
      class CarModel;
      using CarModelPtr = std::shared_ptr<CarModel>;
#pragma db object table("car") pointer(std::shared_ptr)
      class CarModel : public CreateModifyDeleteModel {
        public:
         CarModel() = default;
         ~CarModel() override = default;

         friend class odb::access;
#pragma db id auto column("id")
         uint64_t Id{0};
#pragma db not_null column("plate_number_en") type("VARCHAR(20)") options("CHECK(`plate_number_en` != '')")
         std::string PlateNumberEn;
#pragma db null column("driver_id")
         DriverModelPtr Driver;
#pragma db null column("person_id")
         OrganizationModelPtr Organization;
#pragma db null column("picture_address") type("VARCHAR(1024)") options("CHECK(`picture_address` != '')")
         std::shared_ptr<std::string> PictureAddress;
      };
   }  // namespace model
}  // namespace anar
#endif  // ANAR_CAR_MODEL_HPP
