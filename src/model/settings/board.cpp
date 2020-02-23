#include "board.hpp"

namespace parspark::model {
   PriceBoardPtr PriceBoard::Create() {
      return std::make_shared<PriceBoard>();
   }
   PriceBoard::PriceBoard()
       : BaseModel("PriceBoard") {
   }

   bool PriceBoard::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_address->FromJson(json["address"].toMap());
      return true;
   }
   const QVariantMap PriceBoard::ToJson() const {
      QVariantMap json;
      json["enable"] = m_enable;
      json["address"] = m_address->ToJson();
      return json;
   }

   CapacityBoardPtr CapacityBoard::Create() {
      return std::make_shared<CapacityBoard>();
   }
   CapacityBoard::CapacityBoard()
       : BaseModel("PriceBoard") {
   }

   bool CapacityBoard::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_sendToBoard = json["sendToBoard"].toBool();
      m_address->FromJson(json["address"].toMap());
      m_serverAddress->FromJson(json["serverAddress"].toMap());
      m_parkingName = json["parkingName"].toString();
      return true;
   }
   const QVariantMap CapacityBoard::ToJson() const {
      QVariantMap json;
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
       : BaseModel("Board") {
   }

   bool Board::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_price->FromJson(json["price"].toMap());
      m_capacity->FromJson(json["capacity"].toMap());
      return true;
   }
   const QVariantMap Board::ToJson() const {
      QVariantMap json;
      json["price"] = m_price->ToJson();
      json["capacity"] = m_capacity->ToJson();
      return json;
   }
} // namespace parspark::model
