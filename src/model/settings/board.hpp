#ifndef BOARD_HPP
#define BOARD_HPP

#include "comport.hpp"
#include "server.hpp"

namespace parspark::model {
   class PriceBoard;
   using PriceBoardPtr = std::shared_ptr<PriceBoard>;
   class PriceBoard : public BaseModel {
    public:
      static PriceBoardPtr Create();
      PriceBoard();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      ComPortPtr Address() const {
         return m_address;
      }
      void Address(const ComPortPtr& address) {
         m_address = address;
      }

    private:
      bool m_enable{false};
      ComPortPtr m_address{new ComPort};
   };

   class CapacityBoard;
   using CapacityBoardPtr = std::shared_ptr<CapacityBoard>;
   class CapacityBoard : public BaseModel {
    public:
      static CapacityBoardPtr Create();
      CapacityBoard();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      bool SendToBoard() const {
         return m_sendToBoard;
      }
      void SendToBoard(bool sendToBoard) {
         m_sendToBoard = sendToBoard;
      }
      ComPortPtr Address() const {
         return m_address;
      }
      void Address(const ComPortPtr& address) {
         m_address = address;
      }
      ServerPtr ServerAddress() const {
         return m_serverAddress;
      }
      void ServerAddress(const ServerPtr& serverAddress) {
         m_serverAddress = serverAddress;
      }
      QString ParkingName() const {
         return m_parkingName;
      }
      void ParkingName(const QString& parkingName) {
         m_parkingName = parkingName;
      }

    private:
      bool m_enable{false};
      bool m_sendToBoard{true}; // Opposit of m_sendToServer
      ComPortPtr m_address{new ComPort};
      ServerPtr m_serverAddress{new Server};
      QString m_parkingName{"Parking"};
   };

   class Board;
   using BoardPtr = std::shared_ptr<Board>;
   class Board : public BaseModel {
    public:
      static BoardPtr Create();
      Board();

      bool FromJson(const QVariantMap& json) override;
      const QVariantMap ToJson() const override;

      PriceBoardPtr Price() const {
         return m_price;
      }
      void Price(const PriceBoardPtr& price) {
         m_price = price;
      }
      CapacityBoardPtr Capacity() const {
         return m_capacity;
      }
      void Capacity(const CapacityBoardPtr& capacity) {
         m_capacity = capacity;
      }

    private:
      PriceBoardPtr m_price{new PriceBoard};
      CapacityBoardPtr m_capacity{new CapacityBoard};
   };
} // namespace parspark::model
#endif // BOARD_HPP
