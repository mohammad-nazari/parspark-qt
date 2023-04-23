#ifndef ANAR_CREATE_MODIFY_DELETE_MODEL_HPP
#define ANAR_CREATE_MODIFY_DELETE_MODEL_HPP

#include "user-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object abstract pointer(std::shared_ptr)
            class CreateModifyDeleteModel : public ParsParkModel {
               public:
                CreateModifyDeleteModel(const std::string &name, const std::string &description = "")
                    : ParsParkModel("CreateModifyDelete", "Create Modify Delete") {
                }
                ~CreateModifyDeleteModel() override = default;

                friend class odb::access;
#pragma db not_null column("creating_user_id")
                std::shared_ptr<UserModel> CreatingUser;
#pragma db null column("updating_user_id")
                std::shared_ptr<UserModel> UpdatingUser;
#pragma db not_null column("created_time") type("timestamp") options("DEFAULT CURRENT_TIMESTAMP()")
                time_t CreatedTime;
#pragma db null column("updated_time") type("timestamp") options(", \nCHECK(`updated_time` > `created_time`)")
                std::shared_ptr<time_t> UpdatedTime;
            };
        }  // namespace model
    }      // namespace parspark
}  // namespace anar

#endif  // ANAR_CREATE_MODIFY_DELETE_MODEL_HPP
