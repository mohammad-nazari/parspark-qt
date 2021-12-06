#ifndef ANAR_PARS_PARK_MODEL_BOARD_HPP
#define ANAR_PARS_PARK_MODEL_BOARD_HPP

#include "comport-model.hpp"
#include "server-model.hpp"

namespace anar::parspark::model {
   class PriceBoardModel;
   using PriceBoardModelPtr = std::shared_ptr<PriceBoardModel>;
   class PriceBoardModel : public ParsParkModel {
     public:
      PriceBoardModel()
          : ParsParkModel("PriceBoard") {
      }
      ~PriceBoardModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      bool Enable{false};
      ComPortModel Address;
   };

   class CapacityBoardModel;
   using CapacityBoardModelPtr = std::shared_ptr<CapacityBoardModel>;
   class CapacityBoardModel : public ParsParkModel {
     public:
      CapacityBoardModel()
          : ParsParkModel("PriceBoard") {
      }
      ~CapacityBoardModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      bool Enable{false};
      bool SendToBoard{true};  // Opposite of m_sendToServer
      ComPortModel Address;
      ServerModel ServerAddress;
      std::string ParkingName{"Parking"};
   };

   class BoardModel;
   using BoardModelPtr = std::shared_ptr<BoardModel>;
   class BoardModel : public ParsParkModel {
     public:
      BoardModel()
          : ParsParkModel("Board") {
      }
      ~BoardModel() override = default;

      bool Accept(interfaces::IParsParkModelBindingVisitor *modelBindingVisitor) final {
         return modelBindingVisitor->Visit(this);
      }

      PriceBoardModel Price;
      CapacityBoardModel Capacity;
   };
}  // namespace anar::parspark::model
#endif  // ANAR_PARS_PARK_MODEL_BOARD_HPP
