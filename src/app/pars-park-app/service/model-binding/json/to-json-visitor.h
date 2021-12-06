#ifndef ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP
#define ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP

#include "anar/a-to-json-visitor.hpp"
#include "interface/i-pars-park-model-binding-visitor.hpp"

namespace anar::parspark::service {
   class ToJsonVisitor
       : public anar::service::AToJsonVisitor
       , public interfaces::IParsParkModelBindingVisitor {
     public:
      ToJsonVisitor(json_nlohmann &jsonNlohmann);

      bool Visit(model::UserModel *user) final;
      bool Visit(model::LoginModel *loginModel) final;
      bool Visit(model::AlprByCameraModel *alprByCamera) final;
      bool Visit(model::AlprModel *alpr) final;
      bool Visit(model::PriceBoardModel *priceBoard) final;
      bool Visit(model::CapacityBoardModel *capacityBoard) final;
      bool Visit(model::BoardModel *board) final;
      bool Visit(model::CameraInfoModel *cameraInfo) final;
      bool Visit(model::CameraModel *camera) final;
      bool Visit(model::CardReaderModel *cardReader) final;
      bool Visit(model::ComPortModel *comPort) final;
      bool Visit(model::GateInfoModel *gateInfo) final;
      bool Visit(model::GateModel *gate) final;
      bool Visit(model::TariffModel *tariff) final;
      bool Visit(model::ParkingModel *parking) final;
      bool Visit(model::PaymentInfoModel *paymentInfo) final;
      bool Visit(model::PaymentModel *payment) final;
      bool Visit(model::PrinterModel *printer) final;
      bool Visit(model::ServerModel *server) final;
      bool Visit(model::SettingsModel *settings) final;
      bool Visit(model::SoftwareModel *software) final;
   };
}  // namespace anar::parspark::service

#endif  // ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP