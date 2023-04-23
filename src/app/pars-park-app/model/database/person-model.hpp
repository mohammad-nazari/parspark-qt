#ifndef ANAR_PARS_PARK_MODEL_PERSON_HPP
#define ANAR_PARS_PARK_MODEL_PERSON_HPP

#include <cstdint>
#include <memory>
#include <odb/core.hxx>
#include <string>

#include "model/pars-park-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("person") pointer(std::shared_ptr)
            class PersonModel : public ParsParkModel {
               public:
                PersonModel()
                    : ParsParkModel("Person", "Person") {
                }

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
#pragma db not_null column("email") type("VARCHAR(100)") options("CHECK(`email` != '')")
                std::string Email;
#pragma db null column("address") type("VARCHAR(500)") options("CHECK(`address` != '')")
                std::shared_ptr<std::string> Address;
#pragma db null column("phone") type("VARCHAR(12)") options("CHECK(`phone` != '')")
                std::shared_ptr<std::string> Phone;
#pragma db null column("mobile") type("VARCHAR(12)") options("CHECK(`mobile` != '')")
                std::shared_ptr<std::string> Mobile;
#pragma db null column("picture_address") type("VARCHAR(1024)") options("CHECK(`picture_address` != '')")
                std::shared_ptr<std::string> PictureAddress;
            };
            using PersonModelPtr = std::shared_ptr<PersonModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_PERSON_HPP