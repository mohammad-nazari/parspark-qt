#ifndef MODEL_PARKING_HPP
#define MODEL_PARKING_HPP

#include <cstdint>
#include <memory>
#include <model/base-model.hpp>
#include <string>

namespace parspark::model {
   class Tariff;
   using TariffPtr = std::shared_ptr<Tariff>;
   class Tariff : public BaseModel {
    public:
      static TariffPtr Create();
      static TariffPtr Create(const uint8_t& fromHour,
                              const uint32_t& firstHour,
                              const uint32_t& nextHour);
      Tariff();
      Tariff(const uint8_t& fromHour, const uint32_t& firstHour,
             const uint32_t& nextHour);

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      uint8_t FromHour() const {
         return m_fromHour;
      }
      void FromHour(const uint8_t& fromHour) {
         m_fromHour = fromHour;
      }
      uint8_t ToHoure() const {
         return m_toHoure;
      }
      void ToHoure(const uint8_t& toHoure) {
         m_toHoure = toHoure;
      }
      uint32_t FirstHour() const {
         return m_firstHour;
      }
      void FirstHour(const uint32_t& firstHour) {
         m_firstHour = firstHour;
      }
      uint32_t NextHour() const {
         return m_nextHour;
      }
      void NextHour(const uint32_t& nextHour) {
         m_nextHour = nextHour;
      }

    private:
      uint8_t m_fromHour{7};
      uint8_t m_toHoure{22};
      uint32_t m_firstHour{1800};
      uint32_t m_nextHour{2400};
   };

   class Parking;
   using ParkingPtr = std::shared_ptr<Parking>;
   class Parking : public BaseModel {
    public:
      static ParkingPtr Create();
      Parking();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      QString ParkingName() const {
         return m_parkingName;
      }
      void ParkingName(const QString& parkingName) {
         m_parkingName = parkingName;
      }
      uint16_t Capacity() const {
         return m_capacity;
      }
      void Capacity(const uint16_t& capacity) {
         m_capacity = capacity;
      }
      TariffPtr DayTariff() const {
         return m_dayTariff;
      }
      void DayTariff(const TariffPtr& dayTariff) {
         m_dayTariff = dayTariff;
      }
      TariffPtr NightTariff() const {
         return m_nightTariff;
      }
      void NightTariff(const TariffPtr& nightTariff) {
         m_nightTariff = nightTariff;
      }
      uint32_t ADayTariff() const {
         return m_aDayTariff;
      }
      void ADayTariff(const uint32_t& aDayTariff) {
         m_aDayTariff = aDayTariff;
      }
      uint16_t FreeTime() const {
         return m_freeTime;
      }
      void FreeTime(const uint16_t& freeTime) {
         m_freeTime = freeTime;
      }
      uint8_t LastHourFreeTime() const {
         return m_lastHourFreeTime;
      }
      void LastHourFreeTime(const uint8_t& lastHourFreeTime) {
         m_lastHourFreeTime = lastHourFreeTime;
      }

    private:
      QString m_parkingName{"My Parking"};
      uint16_t m_capacity{100};
      TariffPtr m_dayTariff{new Tariff{7, 2000, 2400}};
      TariffPtr m_nightTariff{new Tariff{22, 2400, 3000}};
      uint32_t m_aDayTariff{16000};
      uint16_t m_freeTime{0};
      uint8_t m_lastHourFreeTime{0};
   };
} // namespace parspark::model
#endif // MODEL_PARKING_HPP
