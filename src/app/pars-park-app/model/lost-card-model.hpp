#ifndef ANAR_LOST_CARD_MODEL_HPP
#define ANAR_LOST_CARD_MODEL_HPP

#include "car-model.hpp"
#include "card-model.hpp"

namespace anar {
   namespace model {
      class LostCardModel;
      using LostCardModelPtr = std::shared_ptr<LostCardModel>;
#pragma db object table("lost_card") pointer(std::shared_ptr)
      class LostCardModel : public CreateModifyDeleteModel {
        public:
         LostCardModel() = default;
         virtual ~LostCardModel() = default;

         friend class odb::access;
#pragma db id auto column("id")
         uint64_t Id{0};
#pragma db not_null column("card_id")
         CardModelPtr Card;
#pragma db not_null column("car_id")
         CarModelPtr Car;
#pragma db not_null column("penalty_cost") options("CHECK(`penalty_cost` > 999)")
         uint32_t PenaltyCost;
#pragma db not_null column("description") type("VARCHAR(4096)") options("CHECK(`description` != '')")
         std::string Description;
      };
   }  // namespace model
}  // namespace anar
class LostCard {};

#endif  // ANAR_LOST_CARD_MODEL_HPP
