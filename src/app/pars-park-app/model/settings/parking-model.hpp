#ifndef ANAR_PARS_PARK_MODEL_PARKING_HPP
#define ANAR_PARS_PARK_MODEL_PARKING_HPP

#include "anar/model.hpp"

namespace anar::parspark::model {
   class TariffModel;
   using TariffModelPtr = std::shared_ptr<TariffModel>;
   class TariffModel : public anar::model::Model {
     public:
      TariffModel()
          : anar::model::Model("Tariff", "Tariff") {
      }
      TariffModel(const uint8_t& fromHour, const uint32_t& firstHour, const uint32_t& nextHour)
          : anar::model::Model("Tariff", "Tariff")
          , FromHour(fromHour)
          , FirstHour(firstHour)
          , NextHour(nextHour) {
      }

      uint8_t FromHour{7};
      uint8_t ToHour{22};
      uint32_t FirstHour{1800};
      uint32_t NextHour{2400};
   };

   class ParkingModel;
   using ParkingModelPtr = std::shared_ptr<ParkingModel>;
   class ParkingModel : public anar::model::Model {
     public:
      ParkingModel()
          : anar::model::Model("Parking", "Parking") {
      }

      std::string ParkingName{"My Parking"};
      uint16_t Capacity{100};
      TariffModel DayTariff{7, 2000, 2400};
      TariffModel NightTariff{22, 2400, 3000};
      uint32_t EveryDayTariff{16000};
      uint16_t FreeTime{0};
      uint8_t LastHourFreeTime{0};
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_PARKING_HPP
