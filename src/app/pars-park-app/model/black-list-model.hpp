#ifndef ANAR_BLACK_LIST_MODEL_HPP
#define ANAR_BLACK_LIST_MODEL_HPP

#include "create-modify-delete-model.hpp"

namespace anar {
   namespace model {
      class BlackListModel;
      using BlackListModelPtr = std::shared_ptr<BlackListModel>;
#pragma db object table("black_list") pointer(std::shared_ptr)
      class BlackListModel : public CreateModifyDeleteModel {
        public:
         BlackListModel() = default;
         virtual ~BlackListModel() = default;

         friend class odb::access;
#pragma db id auto column("id")
         uint64_t Id{0};
#pragma db not_null column("plate_number_en") type("VARCHAR(20)") options("CHECK(`plate_number_en` != '')")
         std::string PlateNumberEn;
#pragma db not_null column("description") type("VARCHAR(4096)") options("CHECK(`description` != '')")
         std::string Description;
      };
   }  // namespace model
}  // namespace anar
#endif  // ANAR_BLACK_LIST_MODEL_HPP
