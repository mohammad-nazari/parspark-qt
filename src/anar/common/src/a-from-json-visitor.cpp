#include "anar/a-from-json-visitor.hpp"

#include <iostream>

#include "anar/database-model.hpp"
#include "anar/error-model.hpp"
#include "anar/exception.hpp"
#include "glog/logging.h"

namespace anar::service {
   AFromJsonVisitor::AFromJsonVisitor(json_nlohmann& jsonNlohmann)
       : m_json(jsonNlohmann) {
   }
   bool AFromJsonVisitor::Visit(model::Model* model) {
      try {
         model->Id = m_json["Id"];
         model->UUId = m_json["UUId"];
         model->Name = m_json["Name"];
         model->Description = m_json["Description"];
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on : " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool AFromJsonVisitor::visit(model::ConstantModel* constant) {
      try {
         if (!constant->Model::Accept(this)) {
            return false;
         }
         constant->Code = m_json["code"];
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'base' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool AFromJsonVisitor::visit(model::ErrorModel* error) {
      try {
         if (!error->Model::Accept(this)) {
            return false;
         }
         AFromJsonVisitor* aFromJsonVisitor;
         error->Code = m_json["Code"];
         aFromJsonVisitor = new AFromJsonVisitor(m_json["Level"]);
         if (!error->Level.Accept(aFromJsonVisitor)) {
            m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'error' json data.");
            m_error->SubErrors.emplace_back(*aFromJsonVisitor->Error());
            return false;
         }
         error->Message = m_json["Code"];
         model::ErrorModel subError;
         for (auto& json : m_json["SubErrors"]) {
            aFromJsonVisitor = new AFromJsonVisitor(json);
            if (!subError.Accept(aFromJsonVisitor)) {
               m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'error' json data.");
               m_error->SubErrors.emplace_back(*aFromJsonVisitor->Error());
               return false;
            }
            error->SubErrors.emplace_back(subError);
         }
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'error' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
   bool AFromJsonVisitor::Visit(model::DataBaseModel* dataBase) {
      try {
         if (!dataBase->Model::Accept(this)) {
            return false;
         }
         dataBase->EngineName = m_json["EngineName"];
         dataBase->HostAddress = m_json["HostAddress"];
         dataBase->DBUserName = m_json["DBUserName"];
         dataBase->DBPassWord = m_json["DBPassWord"];
         dataBase->Port = m_json["Port"];
         dataBase->DatabaseName = m_json["DatabaseName"];
      } catch (std::exception& exception) {
         m_error = std::make_shared<model::ErrorModel>(1, constant::ErrorLevel::ANAR_HIGH_WARNING, "Error on read 'database' json data: " + std::string(exception.what()));
         LOG(INFO) << m_error->Message.c_str();
         return false;
      }
      return true;
   }
}  // namespace anar::service