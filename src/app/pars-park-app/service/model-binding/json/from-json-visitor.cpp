#include "from-json-visitor.hpp"

#include <iostream>

#include "anar/error-manager.hpp"
#include "anar/error-model.hpp"
#include "glog/logging.h"
#include "model/database/user-model.hpp"
#include "model/login-model.hpp"
#include "model/settings/alpr-model.hpp"
#include "model/settings/board-model.hpp"
#include "model/settings/camera-model.hpp"
#include "model/settings/card-reader-model.hpp"
#include "model/settings/comport-model.hpp"
#include "model/settings/gate-model.hpp"
#include "model/settings/parking-model.hpp"
#include "model/settings/payment-model.hpp"
#include "model/settings/printer-model.hpp"
#include "model/settings/server-model.hpp"
#include "model/settings/settings-model.hpp"
#include "model/settings/software-model.hpp"

namespace anar::parspark::service {
    FromJsonVisitor::FromJsonVisitor(nlohmann::ordered_json &jsonNlohmann)
        : anar::common::service::AFromJsonVisitor(jsonNlohmann) {
    }

    bool FromJsonVisitor::Visit(model::ParsParkModel &parPark) {
        return true;
    }
    bool FromJsonVisitor::Visit(model::UserModel &user) {
        try {
            if (!user.Model::Accept(*this)) {
                return false;
            }
            user.UserName = m_json["UserName"];
            user.PassWord = m_json["PassWord"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Person"]);
            if (!user.Person->Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Person' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            user.Type = m_json["Type"];
            user.CreatedTime = m_json["CreatedTime"];
            if (!m_json["UpdatedTime"].is_null()) {
                user.UpdatedTime = std::make_shared<time_t>(m_json["UpdatedTime"]);
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'User' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::LoginModel &login) {
        try {
            if (!login.DataBaseModel::Accept(*this)) {
                return false;
            }
            if (!login.UserModel::Accept(*this)) {
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Login' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::AlprByCameraModel &alprByCamera) {
        try {
            if (!alprByCamera.ParsParkModel::Accept(*this)) {
                return false;
            }
            alprByCamera.Enable = m_json["Enable"];
            alprByCamera.SubmitWithoutEnterPlate = m_json["SubmitWithoutEnterPlate"];
            alprByCamera.SubmitWithoutExitPlate = m_json["SubmitWithoutExitPlate"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'ALPR By Camera' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::AlprModel &alpr) {
        try {
            if (!alpr.ParsParkModel::Accept(*this)) {
                return false;
            }
            alpr.Enable = m_json["Enable"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ByCamera"]);
            if (!alpr.ByCamera.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'By Camera' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'ALPR' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::PriceBoardModel &priceBoard) {
        try {
            if (!priceBoard.ParsParkModel::Accept(*this)) {
                return false;
            }
            priceBoard.Enable = m_json["Enable"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Address"]);
            if (!priceBoard.Address.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Address' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Price Board' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::CapacityBoardModel &capacityBoard) {
        try {
            if (!capacityBoard.ParsParkModel::Accept(*this)) {
                return false;
            }
            capacityBoard.Enable = m_json["Enable"];
            capacityBoard.SendToBoard = m_json["SendToBoard"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ComPortAddress"]);
            if (!capacityBoard.ComPortAddress.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Com Port Address' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ServerAddress"]);
            if (!capacityBoard.ServerAddress.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Server Address' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            capacityBoard.ParkingName = m_json["ParkingName"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Capacity Board' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::BoardModel &board) {
        try {
            if (!board.ParsParkModel::Accept(*this)) {
                return false;
            }
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["PriceBoard"]);
            if (!board.PriceBoard.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Price Board' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["CapacityBoard"]);
            if (!board.CapacityBoard.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Capacity Board' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Board' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::CameraInfoModel &cameraInfo) {
        try {
            if (!cameraInfo.ParsParkModel::Accept(*this)) {
                return false;
            }
            cameraInfo.Enable = m_json["Enable"];
            cameraInfo.Address = m_json["Address"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Camera Info' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::CameraModel &camera) {
        try {
            if (!camera.ParsParkModel::Accept(*this)) {
                return false;
            }
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["EnterCamera"]);
            if (!camera.EnterCamera.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Enter Camera' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ExitCamera"]);
            if (!camera.ExitCamera.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Exit Camera' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Camera' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::CardReaderModel &cardReader) {
        try {
            if (!cardReader.ParsParkModel::Accept(*this)) {
                return false;
            }
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["EnterCardReader"]);
            if (!cardReader.EnterCardReader.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Enter Card Reader' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ExitCardReader"]);
            if (!cardReader.ExitCardReader.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Exit Card Reader' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Card Reader' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::ComPortModel &comPort) {
        try {
            if (!comPort.ParsParkModel::Accept(*this)) {
                return false;
            }
            comPort.PortName = m_json["PortName"];
            comPort.BaudRate = m_json["BaudRate"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'COM Port' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::GateInfoModel &gateInfo) {
        try {
            if (!gateInfo.ParsParkModel::Accept(*this)) {
                return false;
            }
            gateInfo.Enable = m_json["Enable"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ComPortAddress"]);
            if (!gateInfo.ComPortAddress.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'COM Port Address' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            gateInfo.OpenAuto = m_json["OpenAuto"];
            gateInfo.CloseAuto = m_json["CloseAuto"];
            gateInfo.CloseAfter = m_json["CloseAfter"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Gate Info' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::GateModel &gate) {
        try {
            if (!gate.ParsParkModel::Accept(*this)) {
                return false;
            }
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["EnterGate"]);
            if (!gate.EnterGate.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Enter Gate' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ExitGate"]);
            if (!gate.ExitGate.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Exit Gate' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Card Reader' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::TariffModel &tariff) {
        try {
            if (!tariff.ParsParkModel::Accept(*this)) {
                return false;
            }
            tariff.FromHour = m_json["FromHour"];
            tariff.ToHour = m_json["ToHour"];
            tariff.FirstHour = m_json["FirstHour"];
            tariff.NextHour = m_json["NextHour"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Tariff' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::ParkingModel &parking) {
        try {
            if (!parking.ParsParkModel::Accept(*this)) {
                return false;
            }
            parking.ParkingName = m_json["ParkingName"];
            parking.Capacity = m_json["Capacity"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["DayTariff"]);
            if (!parking.DayTariff.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Day Tariff' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["NightTariff"]);
            if (!parking.NightTariff.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Night Tariff' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            parking.EveryDayTariff = m_json["EveryDayTariff"];
            parking.FreeTime = m_json["FreeTime"];
            parking.LastHourFreeTime = m_json["LastHourFreeTime"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Tariff' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::PaymentInfoModel &paymentInfo) {
        try {
            if (!paymentInfo.ParsParkModel::Accept(*this)) {
                return false;
            }
            paymentInfo.Enable = m_json["Enable"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ComPortAddress"]);
            if (!paymentInfo.ComPortAddress.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'COM Port Address' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            paymentInfo.SendDirect = m_json["SendDirect"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Payment Info' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::PaymentModel &payment) {
        try {
            if (!payment.ParsParkModel::Accept(*this)) {
                return false;
            }
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["CitizenDevice"]);
            if (!payment.CitizenDevice.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Citizen Device' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["PosDevice"]);
            if (!payment.PosDevice.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'POS Device' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Payment' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::PrinterModel &printer) {
        try {
            if (!printer.ParsParkModel::Accept(*this)) {
                return false;
            }
            printer.Enable = m_json["Enable"];
            printer.PrinterName = m_json["PrinterName"];
            printer.Title = m_json["Title"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Printer' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::ServerModel &server) {
        try {
            if (!server.ParsParkModel::Accept(*this)) {
                return false;
            }
            server.Address = m_json["Address"];
            server.Port = m_json["Port"];
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Server' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::SettingsModel &settings) {
        try {
            if (!settings.ParsParkModel::Accept(*this)) {
                return false;
            }
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Alpr"]);
            if (!settings.Alpr.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'ALPR' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Board"]);
            if (!settings.Board.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Board' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Camera"]);
            if (!settings.Camera.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Camera' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["CardReader"]);
            if (!settings.CardReader.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Card Reader' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["DataBase"]);
            if (!settings.DataBase.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'DataBase' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Gate"]);
            if (!settings.Gate.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Gate' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Parking"]);
            if (!settings.Parking.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Parking' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Payment"]);
            if (!settings.Payment.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Payment' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Software"]);
            if (!settings.Software.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Software' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
            fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["Printer"]);
            if (!settings.Printer.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Printer' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Settings' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool FromJsonVisitor::Visit(model::SoftwareModel &software) {
        try {
            if (!software.ParsParkModel::Accept(*this)) {
                return false;
            }
            software.ActiveEnter = m_json["ActiveEnter"];
            software.ActiveExit = m_json["ActiveExit"];
            software.IsServer = m_json["IsServer"];
            software.Port = m_json["Port"];
            FromJsonVisitorPtr fromJsonVisitor = std::make_shared<FromJsonVisitor>(m_json["ServerAddress"]);
            if (!software.ServerAddress.Accept(*fromJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Server Address' json data.");
                m_error->SubErrors.emplace_back(*fromJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'Software' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
}  // namespace anar::parspark::service
