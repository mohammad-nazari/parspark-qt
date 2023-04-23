#ifndef ANAR_PARS_PARK_MODEL_CARD_HPP
#define ANAR_PARS_PARK_MODEL_CARD_HPP

#include "create-modify-delete-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("card") pointer(std::shared_ptr)
            class CardModel : public CreateModifyDeleteModel {
               public:
                CardModel()
                    : CreateModifyDeleteModel("Card", "Card") {
                }

                friend class odb::access;
#pragma db id auto column("id")
                uint64_t Id{0};
#pragma db not_null column("code") type("VARCHAR(32)") options("CHECK(`code` != '')")
                std::string Code;
#pragma db not_null column("key") type("VARCHAR(128)") options("CHECK(`key` != '')")
                std::string Key;
            };
            using CardModelPtr = std::shared_ptr<CardModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_CARD_HPP
