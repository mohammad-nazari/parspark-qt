#ifndef ANAR_PARKING_LOG_MODEL_HXX
#define ANAR_PARKING_LOG_MODEL_HXX

#include "subscription-model.hxx"

namespace anar {
   namespace model {
      class ParkingLogModel;
      using ParkingLogModelPtr = std::shared_ptr<ParkingLogModel>;
#pragma db object table("parking_log") pointer(std::shared_ptr)
      class ParkingLogModel : public CreateModifyDeleteModel {
        public:
         ParkingLogModel() = default;
         virtual ~ParkingLogModel() = default;

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
   }  // namespace model
}  // namespace anar

#endif  // ANAR_PARKING_LOG_MODEL_HXX
