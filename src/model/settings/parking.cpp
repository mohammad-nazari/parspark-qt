#include "parking.hpp"

namespace parspark::model {
   TariffPtr Tariff::Create() {
      return std::make_shared<Tariff>();
   }
   TariffPtr Tariff::Create(const uint8_t& fromHour, const uint32_t& firstHour,
                            const uint32_t& nextHour) {
      return std::make_shared<Tariff>(fromHour, firstHour, nextHour);
   }
   Tariff::Tariff()
       : BaseModel("Tariff") {
   }
   Tariff::Tariff(const uint8_t& fromHour, const uint32_t& firstHour,
                  const uint32_t& nextHour)
       : BaseModel("Tariff")
       , m_fromHour(fromHour)
       , m_firstHour(firstHour)
       , m_nextHour(nextHour) {
   }

   bool Tariff::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_fromHour = json["fromHour"].toUInt();
      m_toHoure = json["toHoure"].toUInt();
      m_firstHour = json["firstHour"].toUInt();
      m_nextHour = json["nextHour"].toUInt();
      return true;
   }
   const QVariantMap Tariff::ToJson() const {
      QVariantMap json;
      json["fromHour"] = m_fromHour;
      json["toHoure"] = m_toHoure;
      json["firstHour"] = m_firstHour;
      json["nextHour"] = m_nextHour;
      return json;
   }

   ParkingPtr Parking::Create() {
      return std::make_shared<Parking>();
   }
   Parking::Parking()
       : BaseModel("Parking") {
   }

   bool Parking::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_capacity = json["capacity"].toUInt();
      m_dayTariff->FromJson(json["dayTariff"].toMap());
      m_nightTariff->FromJson(json["nightTariff"].toMap());
      m_aDayTariff = json["aDayTariff"].toUInt();
      m_freeTime = json["freeTime"].toUInt();
      m_lastHourFreeTime = json["lastHourFreeTime"].toUInt();
      return true;
   }
   const QVariantMap Parking::ToJson() const {
      QVariantMap json;
      json["capacity"] = m_capacity;
      json["dayTariff"] = m_dayTariff->ToJson();
      json["nightTariff"] = m_nightTariff->ToJson();
      json["aDayTariff"] = m_aDayTariff;
      json["freeTime"] = m_freeTime;
      json["lastHourFreeTime"] = m_lastHourFreeTime;
      return json;
   }
} // namespace parspark::model
