#include "from-json-visitor.hpp"

#include <iostream>

#include "anar/error-model.hpp"
#include "glog/logging.h"
#include "model/database/user-model.hpp"
#include "model/login-model.hpp"

namespace anar::parspark::service {
   FromJsonVisitor::FromJsonVisitor(json_nlohmann &jsonNlohmann)
       : anar::service::AFromJsonVisitor(jsonNlohmann) {
   }

   bool FromJsonVisitor::Visit(model::UserModel *user) {
      try {
         if (!user->Model::Accept(this)) {
            return false;
         }
         user->UserName = m_json["UserName"];
         user->PassWord = m_json["PassWord"];
         FromJsonVisitor *fromJsonVisitor = new FromJsonVisitor(m_json["Person"]);
         if (!user->Person->Accept(fromJsonVisitor)) {
            m_error = std::make_shared<anar::model::ErrorModel>(1, anar::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'person' json data.");
            m_error->SubErrors.emplace_back(*(fromJsonVisitor->Error()));
            return false;
         };
         user->Type = m_json["Type"];
         fromJsonVisitor = new FromJsonVisitor(m_json["CreatingUser"]);
         if (!user->CreatingUser->Accept(fromJsonVisitor)) {
            m_error = std::make_shared<anar::model::ErrorModel>(1, anar::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'creating user' json data.");
            m_error->SubErrors.emplace_back(*(fromJsonVisitor->Error()));
            return false;
         };
         fromJsonVisitor = new FromJsonVisitor(m_json["UpdatingUser"]);
         if (!user->UpdatingUser->Accept(fromJsonVisitor)) {
            m_error = std::make_shared<anar::model::ErrorModel>(1, anar::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'updating user' json data.");
            m_error->SubErrors.emplace_back(*(fromJsonVisitor->Error()));
            return false;
         };
         user->CreatedTime = m_json["CreatedTime"];
         if (!m_json["UpdatedTime"].is_null()) {
            user->UpdatedTime = std::make_shared<time_t>(m_json["UpdatedTime"]);
         }
      } catch (std::exception &exception) {
         m_error = std::make_shared<anar::model::ErrorModel>(1, anar::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'user' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool FromJsonVisitor::Visit(model::LoginModel *login) {
      try {
         if (!login->DataBaseModel::Accept(this)) {
            return false;
         }
         if (!login->UserModel::Accept(this)) {
            return false;
         }
      } catch (std::exception &exception) {
         m_error = std::make_shared<anar::model::ErrorModel>(1, anar::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'login' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool FromJsonVisitor::Visit(model::AlprByCameraModel *alprByCamera) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::AlprModel *alpr) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::PriceBoardModel *priceBoard) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::CapacityBoardModel *capacityBoard) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::BoardModel *board) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::CameraInfoModel *cameraInfo) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::CameraModel *camera) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::CardReaderModel *cardReader) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::ComPortModel *comPort) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::GateInfoModel *gateInfo) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::GateModel *gate) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::TariffModel *tariff) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::ParkingModel *parking) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::PaymentInfoModel *paymentInfo) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::PaymentModel *payment) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::PrinterModel *printer) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::ServerModel *server) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::SettingsModel *settings) {
      return false;
   }
   bool FromJsonVisitor::Visit(model::SoftwareModel *software) {
      return false;
   }
}  // namespace anar::parspark::service
