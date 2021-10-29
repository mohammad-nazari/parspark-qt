#ifndef ANAR_CREATE_MODIFY_DELETE_MODEL_HPP
#define ANAR_CREATE_MODIFY_DELETE_MODEL_HPP

#include "user-model.hpp"

namespace anar {
   namespace model {
#pragma db object abstract pointer(std::shared_ptr)
      class CreateModifyDeleteModel : public Model {
        public:
         CreateModifyDeleteModel()
             : Model("CreateModifyDelete", "CreateModifyDelete") {
         }
         ~CreateModifyDeleteModel() override = default;

         friend class odb::access;
#pragma db not_null column("creating_user_id")
         UserModelPtr CreatingUser;
#pragma db null column("updating_user_id")
         UserModelPtr UpdatingUser;
#pragma db not_null column("created_time") type("timestamp") options("DEFAULT CURRENT_TIMESTAMP()")
         time_t CreatedTime;
#pragma db null column("updated_time") type("timestamp") options(", \nCHECK(`updated_time` > `created_time`)")
         std::shared_ptr<time_t> UpdatedTime;
      };
   }  // namespace model
}  // namespace anar

#endif  // ANAR_CREATE_MODIFY_DELETE_MODEL_HPP
