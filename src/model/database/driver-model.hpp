#ifndef ANAR_PARS_PARK_MODEL_DRIVER_HPP
#define ANAR_PARS_PARK_MODEL_DRIVER_HPP

#include "organization-model.hpp"
#include "person-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("driver") pointer(std::shared_ptr)
            class DriverModel : public CreateModifyDeleteModel {
               public:
                DriverModel()
                    : CreateModifyDeleteModel("Driver", "Driver") {
                }

                friend class odb::access;
#pragma db id auto column("id")
                uint64_t Id{0};
#pragma db null column("driving_license_number") type("VARCHAR(100)") options("CHECK(`driving_license_number` != '')")
                std::shared_ptr<std::string> DrivingLicenseNumber;
#pragma db not_null column("person_id")
                PersonModelPtr Person;
#pragma db null column("organization_id")
                OrganizationModelPtr Organization;
#pragma db null column("picture_address") type("VARCHAR(1024)") options("CHECK(`picture_address` != '')")
                std::shared_ptr<std::string> PictureAddress;
            };
            using DriverModelPtr = std::shared_ptr<DriverModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_DRIVER_HPP
