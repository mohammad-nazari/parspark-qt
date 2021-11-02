#ifndef ANAR_PARS_PARK_MODEL_CONTACT_HPP
#define ANAR_PARS_PARK_MODEL_CONTACT_HPP

#include "anar/model/model.hpp"
#include "odb/forward.hxx"

namespace anar {
   namespace parspark {
      namespace model {
         class ContactModel;
         using ContactModelPtr = std::shared_ptr<ContactModel>;
#pragma db object table("contact") pointer(std::shared_ptr)
         class ContactModel : public anar::model::Model {
           public:
            ContactModel()
                : anar::model::Model("Contact", "Contact") {
            }

            friend class odb::access;
#pragma db id auto column("id")
            uint64_t Id{0};
#pragma db not_null column("email") type("VARCHAR(100)") options("CHECK(`email` != '')")
            std::string Email;
#pragma db null column("address") type("VARCHAR(500)") options("CHECK(`address` != '')")
            std::shared_ptr<std::string> Address;
#pragma db null column("phone") type("VARCHAR(12)") options("CHECK(`phone` != '')")
            std::shared_ptr<std::string> Phone;
#pragma db null column("mobile") type("VARCHAR(12)") options("CHECK(`mobile` != '')")
            std::shared_ptr<std::string> Mobile;
         };
      }  // namespace model
   }     // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_CONTACT_HPP
