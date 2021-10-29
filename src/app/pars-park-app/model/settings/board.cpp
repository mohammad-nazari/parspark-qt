#include "board.hpp"

namespace anar::model {
   PriceBoardPtr PriceBoard::Create() {
      return std::make_shared<PriceBoard>();
   }
   PriceBoard::PriceBoard()
       : Model("PriceBoard") {
   }

   bool PriceBoard::FromJson(const json_nlohmann& json) {

      m_enable = json["enable"];
      m_address->FromJson(json["address"]);
      return true;
   }
   json_nlohmann PriceBoard::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["address"] = m_address->ToJson();
      return json;
   }

   CapacityBoardPtr CapacityBoard::Create() {
      return std::make_shared<CapacityBoard>();
   }
   CapacityBoard::CapacityBoard()
       : Model("PriceBoard") {
   }

   bool CapacityBoard::FromJson(const json_nlohmann& json) {

      m_enable = json["enable"];
      m_sendToBoard = json["sendToBoard"];
      m_address->FromJson(json["address"]);
      m_serverAddress->FromJson(json["serverAddress"]);
      m_parkingName = json["parkingName"];
      return true;
   }
   json_nlohmann CapacityBoard::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["sendToBoard"] = m_sendToBoard;
      json["address"] = m_address->ToJson();
      json["serverAddress"] = m_serverAddress->ToJson();
      json["parkingName"] = m_parkingName;
      return json;
   }

   BoardPtr Board::Create() {
      return std::make_shared<Board>();
   }
   Board::Board()
       : Model("Board") {
   }

   bool Board::FromJson(const json_nlohmann& json) {

      m_price->FromJson(json["price"]);
      m_capacity->FromJson(json["capacity"]);
      return true;
   }
   json_nlohmann Board::ToJson() {
      json_nlohmann json;
      json["price"] = m_price->ToJson();
      json["capacity"] = m_capacity->ToJson();
      return json;
   }
}  // namespace anar::model
