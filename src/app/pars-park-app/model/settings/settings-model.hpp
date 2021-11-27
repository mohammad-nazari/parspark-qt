#ifndef ANAR_PARS_PARK_MODEL_SETTING_HPP
#define ANAR_PARS_PARK_MODEL_SETTING_HPP

#include "alpr-model.hpp"
#include "anar/database-model.hpp"
#include "board-model.hpp"
#include "camera-model.hpp"
#include "card-reader-model.hpp"
#include "gate-model.hpp"
#include "parking-model.hpp"
#include "payment-model.hpp"
#include "printer-model.hpp"
#include "software-model.hpp"

namespace anar::parspark::model {
   class SettingsModel;
   using SettingsModelPtr = std::shared_ptr<SettingsModel>;
   class SettingsModel : public anar::model::Model {
     public:
      SettingsModel()
          : anar::model::Model("Setting") {
      }

      AlprModel Alpr;
      BoardModel Board;
      CameraModel Camera;
      CardReaderModel CardReader;
      anar::model::DataBaseModel DataBase;
      GateModel Gate;
      ParkingModel Parking;
      PaymentModel Payment;
      SoftwareModel Software;
      PrinterModel Printer;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_SETTING_HPP
