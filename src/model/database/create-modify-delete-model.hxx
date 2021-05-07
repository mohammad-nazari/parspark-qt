#ifndef ANAR_CREATE_MODIFY_DELETE_MODEL_HXX
#define ANAR_CREATE_MODIFY_DELETE_MODEL_HXX

#include "user-model.hxx"

namespace anar {
   namespace model {
#pragma db object abstract pointer(std::shared_ptr)
      class CreateModifyDeleteModel {
        public:
         CreateModifyDeleteModel() = default;
         virtual ~CreateModifyDeleteModel() = default;

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

#endif  // ANAR_CREATE_MODIFY_DELETE_MODEL_HXX
