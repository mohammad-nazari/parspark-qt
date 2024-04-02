#ifndef ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP
#define ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP

#include "anar/a-from-json-visitor.hpp"
#include "interface/i-pars-park-model-binding-visitor.hpp"

namespace anar::parspark::service {
    class FromJsonVisitor
        : public anar::common::service::AFromJsonVisitor
        , public interfaces::IParsParkModelBindingVisitor {
       public:
        FromJsonVisitor(nlohmann::ordered_json &jsonNlohmann);

        bool Visit(model::ParsParkModel &parPark) final;
        bool Visit(model::UserModel &user) final;
        bool Visit(model::LoginModel &loginModel) final;
        bool Visit(model::AlprByCameraModel &alprByCamera) final;
        bool Visit(model::AlprModel &alpr) final;
        bool Visit(model::PriceBoardModel &priceBoard) final;
        bool Visit(model::CapacityBoardModel &capacityBoard) final;
        bool Visit(model::BoardModel &board) final;
        bool Visit(model::CameraInfoModel &cameraInfo) final;
        bool Visit(model::CameraModel &camera) final;
        bool Visit(model::CardReaderModel &cardReader) final;
        bool Visit(model::ComPortModel &comPort) final;
        bool Visit(model::GateInfoModel &gateInfo) final;
        bool Visit(model::GateModel &gate) final;
        bool Visit(model::TariffModel &tariff) final;
        bool Visit(model::ParkingModel &parking) final;
        bool Visit(model::PaymentInfoModel &paymentInfo) final;
        bool Visit(model::PaymentModel &payment) final;
        bool Visit(model::PrinterModel &printer) final;
        bool Visit(model::ServerModel &server) final;
        bool Visit(model::SettingsModel &settings) final;
        bool Visit(model::SoftwareModel &software) final;
    };
    using FromJsonVisitorPtr = std::shared_ptr<FromJsonVisitor>;
}  // namespace anar::parspark::service

#endif  // ANAR_PARS_PARK_SERVICE_FROM_JSON_VISITOR_HPP
