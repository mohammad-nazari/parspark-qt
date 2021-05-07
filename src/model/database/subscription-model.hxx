#ifndef ANAR_SUBSCRIPTION_MODEL_HXX
#define ANAR_SUBSCRIPTION_MODEL_HXX

#include "car-model.hxx"
#include "card-model.hxx"

namespace anar {
   namespace model {
      class SubscriptionModel;
      using SubscriptionModelPtr = std::shared_ptr<SubscriptionModel>;
#pragma db object table("subscription") pointer(std::shared_ptr)
      class SubscriptionModel : public CreateModifyDeleteModel {
        public:
         SubscriptionModel() = default;
         virtual ~SubscriptionModel() = default;

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
   }  // namespace model
}  // namespace anar

#endif  // ANAR_SUBSCRIPTION_MODEL_HXX
