#ifndef ANAR_CARD_MODEL_HXX
#define ANAR_CARD_MODEL_HXX

#include "create-modify-delete-model.hxx"

namespace anar {
   namespace model {
      class CardModel;
      using CardModelPtr = std::shared_ptr<CardModel>;
#pragma db object table("card") pointer(std::shared_ptr)
      class CardModel : public CreateModifyDeleteModel {
        public:
         CardModel() = default;
         ~CardModel() override = default;

         friend class odb::access;
#pragma db id auto column("id")
         uint64_t Id{0};
#pragma db not_null column("code") type("VARCHAR(32)") options("CHECK(`code` != '')")
         std::string Code;
#pragma db not_null column("key") type("VARCHAR(128)") options("CHECK(`key` != '')")
         std::string Key;
      };
   }  // namespace model
}  // namespace anar
#endif  // ANAR_CARD_MODEL_HXX
