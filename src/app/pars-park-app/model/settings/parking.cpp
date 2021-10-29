#include "parking.hpp"

namespace anar::model {
   TariffPtr Tariff::Create() {
      return std::make_shared<Tariff>();
   }
   TariffPtr Tariff::Create(const uint8_t& fromHour, const uint32_t& firstHour, const uint32_t& nextHour) {
      return std::make_shared<Tariff>(fromHour, firstHour, nextHour);
   }
   Tariff::Tariff()
       : Model("Tariff", "Tariff") {
   }
   Tariff::Tariff(const uint8_t& fromHour, const uint32_t& firstHour, const uint32_t& nextHour)
       : Model("Tariff", "Tariff")
       , m_fromHour(fromHour)
       , m_firstHour(firstHour)
       , m_nextHour(nextHour) {
   }

   bool Tariff::FromJson(const json_nlohmann& json) {
      m_fromHour = json["fromHour"];
      m_toHour = json["toHour"];
      m_firstHour = json["firstHour"];
      m_nextHour = json["nextHour"];
      return true;
   }
   json_nlohmann Tariff::ToJson() {
      json_nlohmann json;
      json["fromHour"] = m_fromHour;
      json["toHour"] = m_toHour;
      json["firstHour"] = m_firstHour;
      json["nextHour"] = m_nextHour;
      return json;
   }

   ParkingPtr Parking::Create() {
      return std::make_shared<Parking>();
   }
   Parking::Parking()
       : Model("Parking", "Parking") {
   }

   bool Parking::FromJson(const json_nlohmann& json) {

      m_parkingName = json["parkingName"];
      m_capacity = json["capacity"];
      m_dayTariff->FromJson(json["dayTariff"]);
      m_nightTariff->FromJson(json["nightTariff"]);
      m_aDayTariff = json["aDayTariff"];
      m_freeTime = json["freeTime"];
      m_lastHourFreeTime = json["lastHourFreeTime"];
      return true;
   }
   json_nlohmann Parking::ToJson() {
      json_nlohmann json;
      json["parkingName"] = m_parkingName;
      json["capacity"] = m_capacity;
      json["dayTariff"] = m_dayTariff->ToJson();
      json["nightTariff"] = m_nightTariff->ToJson();
      json["aDayTariff"] = m_aDayTariff;
      json["freeTime"] = m_freeTime;
      json["lastHourFreeTime"] = m_lastHourFreeTime;
      return json;
   }
}  // namespace anar::model
