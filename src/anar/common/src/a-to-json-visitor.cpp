#include "anar/a-to-json-visitor.hpp"

#include <iostream>

#include "anar/database-model.hpp"
#include "anar/error-model.hpp"
#include "anar/exception.hpp"
#include "glog/logging.h"

namespace anar::service {
   AToJsonVisitor::AToJsonVisitor(nlohmann::ordered_json& jsonNlohmann)
       : m_json(jsonNlohmann) {
   }
   bool AToJsonVisitor::Visit(model::Model& model) {
      try {
         m_json["Id"] = model.Id;
         m_json["UUId"] = model.UUId;
         m_json["Name"] = model.Name;
         m_json["Description"] = model.Description;
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on : " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool AToJsonVisitor::visit(model::ConstantModel& constant) {
      try {
         if (!constant.Model::Accept(*this)) {
            return false;
         }
         m_json["code"] = constant.Code;
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'base' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool AToJsonVisitor::visit(model::ErrorModel& error) {
      try {
         if (!error.Model::Accept(*this)) {
            return false;
         }
         m_json["Code"] = error.Code;
         std::shared_ptr<AToJsonVisitor> aToJsonVisitor = std::make_shared<AToJsonVisitor>(m_json["Level"]);
         if (!error.Level.Accept(*aToJsonVisitor)) {
            m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'error' json data.");
            m_error->SubErrors.emplace_back(*aToJsonVisitor->Error());
            return false;
         }
         m_json["Code"] = error.Message;
         nlohmann::ordered_json subErrorJson;
         for (auto& subError : error.SubErrors) {
            aToJsonVisitor = std::make_shared<AToJsonVisitor>(subErrorJson);
            if (!subError.Accept(*aToJsonVisitor)) {
               m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'error' json data.");
               m_error->SubErrors.emplace_back(*aToJsonVisitor->Error());
               return false;
            }
            m_json["SubErrors"].emplace_back(subErrorJson);
         }
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'error' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool AToJsonVisitor::Visit(model::DataBaseModel& dataBase) {
      try {
         if (!dataBase.Model::Accept(*this)) {
            return false;
         }
         m_json["EngineName"] = dataBase.EngineName;
         m_json["HostAddress"] = dataBase.HostAddress;
         m_json["DBUserName"] = dataBase.DBUserName;
         m_json["DBPassWord"] = dataBase.DBPassWord;
         m_json["Port"] = dataBase.Port;
         m_json["DatabaseName"] = dataBase.DatabaseName;
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on write 'database' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
}  // namespace anar::service