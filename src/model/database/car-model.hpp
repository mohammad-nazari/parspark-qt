#ifndef ANAR_PARS_PARK_MODEL_CAR_HPP
#define ANAR_PARS_PARK_MODEL_CAR_HPP

#include "car-model.hpp"
#include "driver-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("car") pointer(std::shared_ptr)
            class CarModel : public CreateModifyDeleteModel {
               public:
                CarModel()
                    : CreateModifyDeleteModel("Car", "Car") {
                }

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
            using CarModelPtr = std::shared_ptr<CarModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_CAR_HPP
