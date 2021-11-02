#ifndef ANAR_PARS_PARK_MODEL_LOST_CARD_HPP
#define ANAR_PARS_PARK_MODEL_LOST_CARD_HPP

#include "car-model.hpp"
#include "card-model.hpp"

namespace anar {
   namespace parspark {
      namespace model {
         class LostCardModel;
         using LostCardModelPtr = std::shared_ptr<LostCardModel>;
#pragma db object table("lost_card") pointer(std::shared_ptr)
         class LostCardModel : public CreateModifyDeleteModel {
           public:
            LostCardModel()
                : CreateModifyDeleteModel("LostCard", "Lost Card") {
            }

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
   }     // namespace parspark
}  // namespace anar

#endif  // ANAR_PARS_PARK_MODEL_LOST_CARD_HPP
