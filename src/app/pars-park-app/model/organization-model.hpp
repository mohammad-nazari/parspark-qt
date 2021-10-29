#ifndef ANAR_ORGANIZATION_MODEL_HXX
#define ANAR_ORGANIZATION_MODEL_HXX

#include "create-modify-delete-model.hpp"

namespace anar {
   namespace model {
      class OrganizationModel;
      using OrganizationModelPtr = std::shared_ptr<OrganizationModel>;
#pragma db object table("organization") pointer(std::shared_ptr)
      class OrganizationModel : public CreateModifyDeleteModel {
        public:
         OrganizationModel() = default;
         virtual ~OrganizationModel() = default;

         friend class odb::access;
#pragma db id auto column("id")
         uint64_t Id{0};
#pragma db not_null column("name") type("VARCHAR(500)") options("CHECK(`name` != '')")
         std::string Name;
#pragma db not_null column("abbreviation") type("VARCHAR(50)") options("CHECK(`abbreviation` != '')")
         std::string Abbreviation;
#pragma db null column("picture_address") type("VARCHAR(1024)") options("CHECK(`picture_address` != '')")
         std::shared_ptr<std::string> PictureAddress;
      };
   }  // namespace model
}  // namespace anar

#endif  // ANAR_ORGANIZATION_MODEL_HXX
