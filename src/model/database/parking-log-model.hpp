#ifndef ANAR_PARS_PARK_MODEL_PARKING_LOG_HXX
#define ANAR_PARS_PARK_MODEL_PARKING_LOG_HXX

#include "subscription-model.hpp"

namespace anar {
    namespace parspark {
        namespace model {
#pragma db object table("parking_log") pointer(std::shared_ptr)
            class ParkingLogModel : public CreateModifyDeleteModel {
               public:
                ParkingLogModel()
                    : CreateModifyDeleteModel("ParkingLog", "Parking Log") {
                }

                friend class odb::access;
#pragma db id auto column("id")
                uint64_t Id{0};
#pragma db not_null column("card_id")
                CardModelPtr Card;
#pragma db null column("enter_plate_number") type("VARCHAR(50)") options("CHECK(`enter_plate_number` != '')")
                std::shared_ptr<std::string> EnterPlateNumber;
#pragma db null column("exit_plate_number") type("VARCHAR(50)") options("CHECK(`exit_plate_number` != '')")
                std::shared_ptr<std::string> ExitPlateNumber;
#pragma db not_null column("entered_time") type("timestamp") options("DEFAULT CURRENT_TIMESTAMP()")
                time_t EnteredTime;
#pragma db null column("exited_time") type("timestamp") options(",\nCHECK(`exited_time` > `entered_time`)")
                std::shared_ptr<time_t> ExitedTime;
#pragma db null column("parking_cost")
                std::shared_ptr<uint32_t> ParkingCost;
#pragma db null column("enter_picture_address") type("VARCHAR(1024)") options("CHECK(`enter_picture_address` != '')")
                std::shared_ptr<std::string> EnterPictureAddress;
#pragma db null column("exit_picture_address") type("VARCHAR(1024)") options("CHECK(`exit_picture_address` != '')")
                std::shared_ptr<std::string> ExitPictureAddress;
#pragma db null column("subscription_id")
                SubscriptionModelPtr Subscription;
            };
            using ParkingLogModelPtr = std::shared_ptr<ParkingLogModel>;
        }  // namespace model
    }      // namespace parspark
}  // namespace anar

#endif  // ANAR_PARS_PARK_MODEL_PARKING_LOG_HXX
