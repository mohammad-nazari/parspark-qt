#ifndef ANAR_PARS_PARK_INTERFACE_MODEL_BINDING_VISITOR_HPP
#define ANAR_PARS_PARK_INTERFACE_MODEL_BINDING_VISITOR_HPP

#include "anar/i-model-binding-visitor.hpp"

namespace anar::parspark::model {
   class LoginModel;
   class UserModel;
   // Setting model classes
   class AlprByCameraModel;
   class AlprModel;
   class PriceBoardModel;
   class CapacityBoardModel;
   class BoardModel;
   class CameraInfoModel;
   class CameraModel;
   class CardReaderModel;
   class ComPortModel;
   class GateInfoModel;
   class GateModel;
   class TariffModel;
   class ParkingModel;
   class PaymentInfoModel;
   class PaymentModel;
   class PrinterModel;
   class ServerModel;
   class SettingsModel;
   class SoftwareModel;
}  // namespace anar::parspark::model

namespace anar::parspark::interfaces {
   class IParsParkModelBindingVisitor : virtual public anar::interfaces::IModelBindingVisitor {
     public:
      virtual bool Visit(model::UserModel *user) = 0;
      virtual bool Visit(model::LoginModel *login) = 0;
      virtual bool Visit(model::AlprByCameraModel *alprByCamera) = 0;
      virtual bool Visit(model::AlprModel *alpr) = 0;
      virtual bool Visit(model::PriceBoardModel *priceBoard) = 0;
      virtual bool Visit(model::CapacityBoardModel *capacityBoard) = 0;
      virtual bool Visit(model::BoardModel *board) = 0;
      virtual bool Visit(model::CameraInfoModel *cameraInfo) = 0;
      virtual bool Visit(model::CameraModel *camera) = 0;
      virtual bool Visit(model::CardReaderModel *cardReader) = 0;
      virtual bool Visit(model::ComPortModel *comPort) = 0;
      virtual bool Visit(model::GateInfoModel *gateInfo) = 0;
      virtual bool Visit(model::GateModel *gate) = 0;
      virtual bool Visit(model::TariffModel *tariff) = 0;
      virtual bool Visit(model::ParkingModel *parking) = 0;
      virtual bool Visit(model::PaymentInfoModel *paymentInfo) = 0;
      virtual bool Visit(model::PaymentModel *payment) = 0;
      virtual bool Visit(model::PrinterModel *printer) = 0;
      virtual bool Visit(model::ServerModel *server) = 0;
      virtual bool Visit(model::SettingsModel *settings) = 0;
      virtual bool Visit(model::SoftwareModel *software) = 0;
   };
}  // namespace anar::parspark::interfaces
#endif  // ANAR_PARS_PARK_INTERFACE_MODEL_BINDING_VISITOR_HPP
