#include "anar/json-parser.hpp"

namespace anar::service {
   model::ErrorModel JsonParserService::FromJson(model::Model& model, nlohmann::ordered_json& json) {
      model::ErrorModel errorModelResult;
      try {
         model.UUId = json["uuid"];
         model.Name = json["name"];
         model.Description = json["description"];
      } catch (std::exception& exception) {
         // ToDo: Generate a error and throw out a log message
         errorModelResult.Code = 1;
         errorModelResult.Message = "Error on : " + std::string(exception.what());
         errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
      }
      return errorModelResult;
   }
   model::ErrorModel JsonParserService::ToJson(const model::Model& model, nlohmann::ordered_json& json) {
      model::ErrorModel errorModelResult;
      try {
         json["uuid"] = model.UUId;
         json["name"] = model.Name;
         json["description"] = model.Description;
      } catch (std::exception& exception) {
         // ToDo: Generate a error and throw out a log message
         errorModelResult.Code = 1;
         errorModelResult.Message = "Error on : " + std::string(exception.what());
         errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
      }
      return errorModelResult;
   }

   model::ErrorModel JsonParserService::FromJson(model::ConstantModel& constantModel, nlohmann::ordered_json& json) {
      model::ErrorModel errorModelResult = FromJson((model::Model&)constantModel, json);
      if (errorModelResult.Code < 1) {
         return errorModelResult;
      }
      try {
         constantModel.Code = json["code"];
      } catch (std::exception& exception) {
         // ToDo: Generate a error and throw out a log message
         errorModelResult.Code = 1;
         errorModelResult.Message = "Error on : " + std::string(exception.what());
         errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
      }
      return errorModelResult;
   }
   model::ErrorModel JsonParserService::ToJson(const model::ConstantModel& constantModel, nlohmann::ordered_json& json) {
      model::ErrorModel errorModelResult = ToJson((model::Model&)constantModel, json);
      if (errorModelResult.Code < 1) {
         return errorModelResult;
      }
      try {
         json["code"] = constantModel.Code;
      } catch (std::exception& exception) {
         // ToDo: Generate a error and throw out a log message
         errorModelResult.Code = 1;
         errorModelResult.Message = "Error on : " + std::string(exception.what());
         errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
      }
      return errorModelResult;
   }

   model::ErrorModel JsonParserService::FromJson(model::ErrorModel& errorModel, nlohmann::ordered_json& json) {
      model::ErrorModel errorModelResult = FromJson((model::Model&)errorModel, json);
      if (errorModelResult.Code < 1) {
         return errorModelResult;
      }
      try {
         errorModel.Code = json["code"];
         FromJson(errorModel.Level, json["level"]);
         errorModel.Message = json["message"];
         model::ErrorModel errorModelTemp;
         if (json["subErrors"].is_array()) {
            for (auto& subError : json["sub-errors"]) {
               errorModelResult = FromJson(errorModelTemp, subError);
               if (errorModelResult.Code < 1) {
                  return errorModelResult;
               }
               errorModel.SubErrors.emplace_back(errorModelTemp);
            }
         }
      } catch (std::exception& exception) {
         // ToDo: Generate a error and throw out a log message
         errorModelResult.Code = 1;
         errorModelResult.Message = "Error on : " + std::string(exception.what());
         errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
      }
      return errorModelResult;
   }
   model::ErrorModel JsonParserService::ToJson(const model::ErrorModel& errorModel, nlohmann::ordered_json& json) {
      model::ErrorModel errorModelResult = FromJson((model::Model&)errorModel, json);
      if (errorModelResult.Code < 1) {
         return errorModelResult;
      }
      try {
         json["code"] = errorModel.Code;
         ToJson(errorModel.Level, json["level"]);
         json["message"] = errorModel.Message;
         nlohmann::ordered_json jsonTemp = nlohmann::ordered_json::object();
         for (const auto& subError : errorModel.SubErrors) {
            errorModelResult = ToJson(subError, jsonTemp);
            if (errorModelResult.Code < 1) {
               return errorModelResult;
            }
            json["sub-errors"].push_back(jsonTemp);
         }
      } catch (std::exception& exception) {
         // ToDo: Generate a error and throw out a log message
         errorModelResult.Code = 1;
         errorModelResult.Message = "Error on : " + std::string(exception.what());
         errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
      }
      return errorModelResult;
   }
}  // namespace anar::service