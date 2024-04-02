#ifndef ANAR_PARS_PARK_MODEL_SUBSCRIPTION_HPP
#define ANAR_PARS_PARK_MODEL_SUBSCRIPTION_HPP

#include "car-model.hpp"
#include "card-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("subscription") pointer(std::shared_ptr)
            class SubscriptionModel : public CreateModifyDeleteModel {
               public:
                SubscriptionModel()
                    : CreateModifyDeleteModel("Subscription", "Subscription") {
                }

                friend class odb::access;
#pragma db id auto column("id")
                uint64_t Id{0};
#pragma db not_null column("card_id")
                CardModelPtr Card;
#pragma db not_null column("validate_times_json") type("TEXT") options("CHECK(`validate_times_json` != '')")
                std::string ValidateTimesJson;
#pragma db not_null column("subscription_cost") options("CHECK(`subscription_cost` > 999)")
                uint32_t subscription_cost;
#pragma db null column("car_id")
                CarModelPtr Car;
#pragma db null column("driver_id")
                DriverModelPtr Driver;
#pragma db null column("organization_id")
                OrganizationModelPtr Organization;
            };
            using SubscriptionModelPtr = std::shared_ptr<SubscriptionModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar
#endif  // ANAR_PARS_PARK_MODEL_SUBSCRIPTION_HPP
