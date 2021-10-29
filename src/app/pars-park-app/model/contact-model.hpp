#ifndef ANAR_CONTACT_MODEL_HPP
#define ANAR_CONTACT_MODEL_HPP

#include <memory>
#include <odb/core.hxx>
#include <string>

#include "anar/model/model.hpp"

namespace anar {
   namespace model {
      class ContactModel;
      using ContactModelPtr = std::shared_ptr<ContactModel>;
#pragma db object table("contact") pointer(std::shared_ptr)
      class ContactModel : public Model {
        public:
         ContactModel()
             : Model("Contact", "Contact") {
         }
         ~ContactModel() override = default;

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
}  // namespace anar
#endif  // ANAR_CONTACT_MODEL_HPP
