#ifndef ANAR_PARS_PARK_MODEL_USER_HPP
#define ANAR_PARS_PARK_MODEL_USER_HPP

#include "model/pars-park-model.hpp"
#include "person-model.hpp"

namespace anar {
   namespace parspark {
      namespace model {
         enum class UserType : uint8_t { admin, manager, employee };
         class UserModel;
         using UserModelPtr = std::shared_ptr<UserModel>;
#pragma db object table("user") pointer(std::shared_ptr) table("user")
         class UserModel : public virtual ParsParkModel {
           public:
            UserModel()
                : ParsParkModel("User", "User") {
            }

            bool Accept(interfaces::IParsParkModelBindingVisitor & modelBindingVisitor) override {
               return modelBindingVisitor.Visit(*this);
            }

            friend class odb::access;
#pragma db id auto column("id")
            uint64_t Id{0};
#pragma db not_null column("user_name") type("VARCHAR(100)") unique options("CHECK(LENGTH(`user_name`) > 6)")
            std::string UserName;
#pragma db not_null column("pass_word") type("VARCHAR(1024)") options("CHECK(LENGTH(`pass_word`) > 64)")  // Hash code
            std::string PassWord;
#pragma db null column("person_id")
            PersonModelPtr Person;
#pragma db not_null column("type") options("DEFAULT 'employee'")
            UserType Type{UserType::employee};
#pragma db not_null column("creating_user_id")
            UserModelPtr CreatingUser;
#pragma db null column("updating_user_id")
            UserModelPtr UpdatingUser;
#pragma db not_null column("created_time") type("TIMESTAMP(6)") options("DEFAULT CURRENT_TIMESTAMP()")
            time_t CreatedTime;
#pragma db null column("updated_time") type("TIMESTAMP(6)") options(", \nCHECK(`updated_time` > `created_time`)")
            std::shared_ptr<time_t> UpdatedTime;
         };
      }  // namespace model
   }     // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_USER_HPP
