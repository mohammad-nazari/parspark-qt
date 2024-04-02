#ifndef ANAR_PARS_PARK_MODEL_BLACK_LIST_HPP
#define ANAR_PARS_PARK_MODEL_BLACK_LIST_HPP

#include "create-modify-delete-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("black_list") pointer(std::shared_ptr)
            class BlackListModel : public CreateModifyDeleteModel {
               public:
                BlackListModel()
                    : CreateModifyDeleteModel("BlackList", "Black List") {
                }

                friend class odb::access;
#pragma db id auto column("id")
                uint64_t Id{0};
#pragma db not_null column("plate_number_en") type("VARCHAR(20)") options("CHECK(`plate_number_en` != '')")
                std::string PlateNumberEn;
#pragma db not_null column("description") type("VARCHAR(4096)") options("CHECK(`description` != '')")
                std::string Description;
            };
            using BlackListModelPtr = std::shared_ptr<BlackListModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_BLACK_LIST_HPP
