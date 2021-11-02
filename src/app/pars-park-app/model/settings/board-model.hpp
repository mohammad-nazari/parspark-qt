#ifndef ANAR_PARS_PARK_MODEL_BOARD_HPP
#define ANAR_PARS_PARK_MODEL_BOARD_HPP

#include "comport-model.hpp"
#include "server-model.hpp"

namespace anar::parspark::model {
   class PriceBoardModel;
   using PriceBoardModelPtr = std::shared_ptr<PriceBoardModel>;
   class PriceBoardModel : public anar::model::Model {
     public:
      PriceBoardModel()
          : anar::model::Model("PriceBoard") {
      }

      bool Enable{false};
      ComPortModel Address;
   };

   class CapacityBoardModel;
   using CapacityBoardModelPtr = std::shared_ptr<CapacityBoardModel>;
   class CapacityBoardModel : public anar::model::Model {
     public:
      CapacityBoardModel()
          : anar::model::Model("PriceBoard") {
      }

      bool Enable{false};
      bool SendToBoard{true};  // Opposite of m_sendToServer
      ComPortModel Address;
      ServerModel ServerAddress;
      std::string ParkingName{"Parking"};
   };

   class BoardModel;
   using BoardModelPtr = std::shared_ptr<BoardModel>;
   class BoardModel : public anar::model::Model {
     public:
      BoardModel()
          : anar::model::Model("Board") {
      }

      PriceBoardModel Price;
      CapacityBoardModel Capacity;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_BOARD_HPP
