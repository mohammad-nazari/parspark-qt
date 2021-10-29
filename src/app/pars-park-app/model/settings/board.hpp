#ifndef ANAR_BOARD_HPP
#define ANAR_BOARD_HPP

#include "comport.hpp"
#include "server.hpp"

namespace anar::model {
   class PriceBoard;
   using PriceBoardPtr = std::shared_ptr<PriceBoard>;
   class PriceBoard : public Model {
     public:
      static PriceBoardPtr Create();
      PriceBoard();

      bool FromJson(const json_nlohmann& json);
      json_nlohmann ToJson();

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      [[nodiscard]] ComPortPtr Address() const {
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
   class CapacityBoard : public Model {
     public:
      static CapacityBoardPtr Create();
      CapacityBoard();

      bool FromJson(const json_nlohmann& json) ;
      json_nlohmann ToJson();

      [[nodiscard]] bool Enable() const {
         return m_enable;
      }
      void Enable(bool enable) {
         m_enable = enable;
      }
      [[nodiscard]] bool SendToBoard() const {
         return m_sendToBoard;
      }
      void SendToBoard(bool sendToBoard) {
         m_sendToBoard = sendToBoard;
      }
      [[nodiscard]] const ComPortPtr& Address() const {
         return m_address;
      }
      void Address(const ComPortPtr& address) {
         m_address = address;
      }
      [[nodiscard]] const ServerPtr& ServerAddress() const {
         return m_serverAddress;
      }
      void ServerAddress(const ServerPtr& serverAddress) {
         m_serverAddress = serverAddress;
      }
      [[nodiscard]] const std::string& ParkingName() const {
         return m_parkingName;
      }
      void ParkingName(const std::string& parkingName) {
         m_parkingName = parkingName;
      }

     private:
      bool m_enable{false};
      bool m_sendToBoard{true};  // Opposite of m_sendToServer
      ComPortPtr m_address{new ComPort};
      ServerPtr m_serverAddress{new Server};
      std::string m_parkingName{"Parking"};
   };

   class Board;
   using BoardPtr = std::shared_ptr<Board>;
   class Board : public Model {
     public:
      static BoardPtr Create();
      Board();

      bool FromJson(const json_nlohmann& json);
      json_nlohmann ToJson();

      [[nodiscard]] const PriceBoardPtr& Price() const {
         return m_price;
      }
      void Price(const PriceBoardPtr& price) {
         m_price = price;
      }
      [[nodiscard]] const CapacityBoardPtr& Capacity() const {
         return m_capacity;
      }
      void Capacity(const CapacityBoardPtr& capacity) {
         m_capacity = capacity;
      }

     private:
      PriceBoardPtr m_price{new PriceBoard};
      CapacityBoardPtr m_capacity{new CapacityBoard};
   };
}  // namespace anar::model
#endif  // ANAR_BOARD_HPP
