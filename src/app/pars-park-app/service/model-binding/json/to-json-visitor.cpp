#include "to-json-visitor.hpp"

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
    ToJsonVisitor::ToJsonVisitor(nlohmann::ordered_json &jsonNlohmann)
        : anar::common::service::AToJsonVisitor(jsonNlohmann) {
    }

    bool ToJsonVisitor::Visit(model::ParsParkModel &parPark) {
        return true;
    }
    bool ToJsonVisitor::Visit(model::UserModel &user) {
        try {
            if (!user.Model::Accept(*this)) {
                return false;
            }
            m_json["UserName"] = user.UserName;
            m_json["PassWord"] = user.PassWord;
            std::shared_ptr<ToJsonVisitor> toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Person"]);
            if (!user.Person->Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'person' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            };
            m_json["Type"] = user.Type;
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["CreatingUser"]);
            if (!user.CreatingUser->Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Creating User' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            };
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["UpdatingUser"]);
            if (!user.UpdatingUser->Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'updating user' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            };
            m_json["CreatedTime"] = user.CreatedTime;
            if (!m_json["UpdatedTime"].is_null()) {
                user.UpdatedTime = std::make_shared<time_t>(m_json["UpdatedTime"]);
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'user' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::LoginModel &login) {
        try {
            if (!login.DataBaseModel::Accept(*this)) {
                return false;
            }
            if (!login.UserModel::Accept(*this)) {
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'login' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::AlprByCameraModel &alprByCamera) {
        try {
            if (!alprByCamera.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = alprByCamera.Enable;
            m_json["SubmitWithoutEnterPlate"] = alprByCamera.SubmitWithoutEnterPlate;
            m_json["SubmitWithoutExitPlate"] = alprByCamera.SubmitWithoutExitPlate;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'ALPR By Camera' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::AlprModel &alpr) {
        try {
            if (!alpr.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = alpr.Enable;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ByCamera"]);
            if (!alpr.ByCamera.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'By Camera' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'ALPR' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::PriceBoardModel &priceBoard) {
        try {
            if (!priceBoard.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = priceBoard.Enable;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Address"]);
            if (!priceBoard.Address.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Address' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Price Board' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::CapacityBoardModel &capacityBoard) {
        try {
            if (!capacityBoard.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = capacityBoard.Enable;
            m_json["SendToBoard"] = capacityBoard.SendToBoard;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ComPortAddress"]);
            if (!capacityBoard.ComPortAddress.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Com Port Address' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ServerAddress"]);
            if (!capacityBoard.ServerAddress.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Server Address' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            m_json["ParkingName"] = capacityBoard.ParkingName;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Capacity Board' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::BoardModel &board) {
        try {
            if (!board.ParsParkModel::Accept(*this)) {
                return false;
            }
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["PriceBoard"]);
            if (!board.PriceBoard.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Price Board' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["CapacityBoard"]);
            if (!board.CapacityBoard.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Capacity Board' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Board' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::CameraInfoModel &cameraInfo) {
        try {
            if (!cameraInfo.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = cameraInfo.Enable;
            m_json["Address"] = cameraInfo.Address;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Camera Info' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::CameraModel &camera) {
        try {
            if (!camera.ParsParkModel::Accept(*this)) {
                return false;
            }
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["EnterCamera"]);
            if (!camera.EnterCamera.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Enter Camera' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ExitCamera"]);
            if (!camera.ExitCamera.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Exit Camera' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Camera' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::CardReaderModel &cardReader) {
        try {
            if (!cardReader.ParsParkModel::Accept(*this)) {
                return false;
            }
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["EnterCardReader"]);
            if (!cardReader.EnterCardReader.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Enter Card Reader' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ExitCardReader"]);
            if (!cardReader.ExitCardReader.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Exit Card Reader' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Card Reader' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::ComPortModel &comPort) {
        try {
            if (!comPort.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["PortName"] = comPort.PortName;
            m_json["BaudRate"] = comPort.BaudRate;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'COM Port' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::GateInfoModel &gateInfo) {
        try {
            if (!gateInfo.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = gateInfo.Enable;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ComPortAddress"]);
            if (!gateInfo.ComPortAddress.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'COM Port Address' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            m_json["OpenAuto"] = gateInfo.OpenAuto;
            m_json["CloseAuto"] = gateInfo.CloseAuto;
            m_json["CloseAfter"] = gateInfo.CloseAfter;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Gate Info' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::GateModel &gate) {
        try {
            if (!gate.ParsParkModel::Accept(*this)) {
                return false;
            }
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["EnterGate"]);
            if (!gate.EnterGate.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Enter Gate' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ExitGate"]);
            if (!gate.ExitGate.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Exit Gate' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Card Reader' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::TariffModel &tariff) {
        try {
            if (!tariff.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["FromHour"] = tariff.FromHour;
            m_json["ToHour"] = tariff.ToHour;
            m_json["FirstHour"] = tariff.FirstHour;
            m_json["NextHour"] = tariff.NextHour;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Tariff' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::ParkingModel &parking) {
        try {
            if (!parking.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["ParkingName"] = parking.ParkingName;
            m_json["Capacity"] = parking.Capacity;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["DayTariff"]);
            if (!parking.DayTariff.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Day Tariff' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["NightTariff"]);
            if (!parking.NightTariff.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Night Tariff' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            m_json["EveryDayTariff"] = parking.EveryDayTariff;
            m_json["FreeTime"] = parking.FreeTime;
            m_json["LastHourFreeTime"] = parking.LastHourFreeTime;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Tariff' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::PaymentInfoModel &paymentInfo) {
        try {
            if (!paymentInfo.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = paymentInfo.Enable;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ComPortAddress"]);
            if (!paymentInfo.ComPortAddress.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'COM Port Address' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            m_json["SendDirect"] = paymentInfo.SendDirect;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Payment Info' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::PaymentModel &payment) {
        try {
            if (!payment.ParsParkModel::Accept(*this)) {
                return false;
            }
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["CitizenDevice"]);
            if (!payment.CitizenDevice.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Citizen Device' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["PosDevice"]);
            if (!payment.PosDevice.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'POS Device' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Payment' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::PrinterModel &printer) {
        try {
            if (!printer.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Enable"] = printer.Enable;
            m_json["PrinterName"] = printer.PrinterName;
            m_json["Title"] = printer.Title;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Printer' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::ServerModel &server) {
        try {
            if (!server.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["Address"] = server.Address;
            m_json["Port"] = server.Port;
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Server' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::SettingsModel &settings) {
        try {
            if (!settings.ParsParkModel::Accept(*this)) {
                return false;
            }
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Alpr"]);
            if (!settings.Alpr.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'ALPR' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Board"]);
            if (!settings.Board.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Board' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Camera"]);
            if (!settings.Camera.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Camera' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["CardReader"]);
            if (!settings.CardReader.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Card Reader' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["DataBase"]);
            if (!settings.DataBase.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'DataBase' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Gate"]);
            if (!settings.Gate.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Gate' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Parking"]);
            if (!settings.Parking.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Parking' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Payment"]);
            if (!settings.Payment.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Payment' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Software"]);
            if (!settings.Software.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Software' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
            toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["Printer"]);
            if (!settings.Printer.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Printer' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Settings' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
    bool ToJsonVisitor::Visit(model::SoftwareModel &software) {
        try {
            if (!software.ParsParkModel::Accept(*this)) {
                return false;
            }
            m_json["ActiveEnter"] = software.ActiveEnter;
            m_json["ActiveExit"] = software.ActiveExit;
            m_json["IsServer"] = software.IsServer;
            m_json["Port"] = software.Port;
            ToJsonVisitorPtr toJsonVisitor = std::make_shared<ToJsonVisitor>(m_json["ServerAddress"]);
            if (!software.ServerAddress.Accept(*toJsonVisitor)) {
                m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Server Address' json data.");
                m_error->SubErrors.emplace_back(*toJsonVisitor->Error());
                return false;
            }
        } catch (std::exception &exception) {
            m_error = anar::common::service::ErrorManager::GenerateErrorPtr(1, anar::common::constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'Software' json data: " + std::string(exception.what()));
            LOG(INFO) << m_error->Message.c_str();
            return false;
        }
        return true;
    }
}  // namespace anar::parspark::service