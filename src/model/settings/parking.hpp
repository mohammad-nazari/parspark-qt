#ifndef ANAR_PARKING_HPP
#define ANAR_PARKING_HPP

#include <cstdint>
#include <memory>
#include <string>

#include "model/model.hpp"

namespace anar::model {
   class Tariff;
   using TariffPtr = std::shared_ptr<Tariff>;
   class Tariff : public Model {
     public:
      static TariffPtr Create();
      static TariffPtr Create(const uint8_t& fromHour, const uint32_t& firstHour, const uint32_t& nextHour);
      Tariff();
      Tariff(const uint8_t& fromHour, const uint32_t& firstHour, const uint32_t& nextHour);

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] uint8_t FromHour() const {
         return m_fromHour;
      }
      void FromHour(uint8_t fromHour) {
         m_fromHour = fromHour;
      }
      [[nodiscard]] uint8_t ToHour() const {
         return m_toHour;
      }
      void ToHour(uint8_t toHour) {
         m_toHour = toHour;
      }
      [[nodiscard]] uint32_t FirstHour() const {
         return m_firstHour;
      }
      void FirstHour(uint32_t firstHour) {
         m_firstHour = firstHour;
      }
      [[nodiscard]] uint32_t NextHour() const {
         return m_nextHour;
      }
      void NextHour(uint32_t nextHour) {
         m_nextHour = nextHour;
      }

     private:
      uint8_t m_fromHour{7};
      uint8_t m_toHour{22};
      uint32_t m_firstHour{1800};
      uint32_t m_nextHour{2400};
   };

   class Parking;
   using ParkingPtr = std::shared_ptr<Parking>;
   class Parking : public Model {
     public:
      static ParkingPtr Create();
      Parking();

      bool FromJson(const json_nlohmann& json) override;
      json_nlohmann ToJson() override;

      [[nodiscard]] const std::string& ParkingName() const {
         return m_parkingName;
      }
      void ParkingName(const std::string& parkingName) {
         m_parkingName = parkingName;
      }
      [[nodiscard]] uint16_t Capacity() const {
         return m_capacity;
      }
      void Capacity(uint16_t capacity) {
         m_capacity = capacity;
      }
      [[nodiscard]] const TariffPtr& DayTariff() const {
         return m_dayTariff;
      }
      void DayTariff(const TariffPtr& dayTariff) {
         m_dayTariff = dayTariff;
      }
      [[nodiscard]] const TariffPtr& NightTariff() const {
         return m_nightTariff;
      }
      void NightTariff(const TariffPtr& nightTariff) {
         m_nightTariff = nightTariff;
      }
      [[nodiscard]] uint32_t ADayTariff() const {
         return m_aDayTariff;
      }
      void ADayTariff(uint32_t aDayTariff) {
         m_aDayTariff = aDayTariff;
      }
      [[nodiscard]] uint16_t FreeTime() const {
         return m_freeTime;
      }
      void FreeTime(uint16_t freeTime) {
         m_freeTime = freeTime;
      }
      [[nodiscard]] uint8_t LastHourFreeTime() const {
         return m_lastHourFreeTime;
      }
      void LastHourFreeTime(uint8_t lastHourFreeTime) {
         m_lastHourFreeTime = lastHourFreeTime;
      }

     private:
      std::string m_parkingName{"My Parking"};
      uint16_t m_capacity{100};
      TariffPtr m_dayTariff{new Tariff{7, 2000, 2400}};
      TariffPtr m_nightTariff{new Tariff{22, 2400, 3000}};
      uint32_t m_aDayTariff{16000};
      uint16_t m_freeTime{0};
      uint8_t m_lastHourFreeTime{0};
   };
}  // namespace anar::model
#endif  // ANAR_PARKING_HPP
