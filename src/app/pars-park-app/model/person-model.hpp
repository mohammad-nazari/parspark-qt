#ifndef ANAR_PERSON_MODEL_HXX
#define ANAR_PERSON_MODEL_HXX

#include "contact-model.hpp"

namespace anar {
   namespace model {
      class PersonModel;
      using PersonModelPtr = std::shared_ptr<PersonModel>;
#pragma db object table("person") pointer(std::shared_ptr)
      class PersonModel : public Model {
        public:
         PersonModel()
             : Model("Person", "Person") {
         }
         ~PersonModel() override = default;

         friend class odb::access;
#pragma db id auto column("id")
         uint64_t Id{0};
#pragma db not_null column("first_name") type("VARCHAR(100)") options("CHECK(`first_name` != '')")
         std::string FirstName;
#pragma db not_null column("last_name") type("VARCHAR(100)") options("CHECK(`last_name` != '')")
         std::string LastName;
#pragma db null column("national_card_number") options("CHECK(`national_card_number` BETWEEN 1000000000 AND 9999999999)")
         std::shared_ptr<uint64_t> NationalCardNumber;
#pragma db null column("age") options("CHECK(`age` BETWEEN 1 AND 255)")
         std::shared_ptr<uint8_t> Age;
#pragma db null column("person_contact_id")
         ContactModelPtr PersonContact;
#pragma db null column("business_contact_id")
         ContactModelPtr BusinessContact;
#pragma db null column("picture_address") type("VARCHAR(1024)") options("CHECK(`picture_address` != '')")
         std::shared_ptr<std::string> PictureAddress;
      };
   }  // namespace model
}  // namespace anar
#endif  // ANAR_PERSON_MODEL_HXX