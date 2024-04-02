#ifndef ANAR_SERVICE_JSON_PARSER_HPP
#define ANAR_SERVICE_JSON_PARSER_HPP

#include <fstream>
#include <nlohmann/json.hpp>
#include <string>

#include "anar/service.hpp"

namespace anar::common::service {
    class JsonParserService : public Service {
        template <class JsonableClass>
        model::ErrorModel FromJsonString(JsonableClass& jsonableClass, const std::string& jsonString) {
            model::ErrorModel errorModelResult;
            try {
                // Parse JSON format string to JSON document
                nlohmann::ordered_json json = nlohmann::ordered_json::parse(jsonString);
                // Read object data from JSON document
                errorModelResult = FromJson(jsonableClass, json);
#ifdef UNIX
                // In nlohman json class some memory does not released by linux base OS.<br>
                // We release this memory every time use this method
                malloc_trim(0);  // Trim all memories
#endif
            } catch (std::exception& exception) {
                // ToDo: Generate a error and throw out a log message
                errorModelResult.Code = 1;
                errorModelResult.Message = "Error: " + std::string(exception.what());
                errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
            }
            return errorModelResult;
        }
        template <class JsonableClass>
        model::ErrorModel ToJsonString(const JsonableClass& jsonableClass, std::string& jsonString) {
            model::ErrorModel errorModelResult;
            try {
                errorModelResult = ToJson(jsonableClass, jsonString);
#ifdef UNIX
                // In nlohman json class some memory does not released by linux base OS.<br>
                // We release this memory every time use this method
                malloc_trim(0);  // Trim all memories
#endif
            } catch (std::exception& exception) {
                // ToDo: Generate a error and throw out a log message
                errorModelResult.Code = 1;
                errorModelResult.Message = "Error on : " + std::string(exception.what());
                errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
            }
            return errorModelResult;
        }

        template <class JsonableClass>
        model::ErrorModel FromJsonFile(JsonableClass& jsonableClass, const std::string& jsonFilePath) {
            model::ErrorModel errorModelResult;
            std::ifstream ifStream(jsonFilePath);
            try {
                // Parse JSON format string to JSON document
                if (ifStream.is_open()) {
                    nlohmann::ordered_json json = nlohmann::ordered_json::parse(ifStream);
                    // Read object data from JSON document
                    errorModelResult = FromJson(jsonableClass, json);
                }
#ifdef UNIX
                // In nlohman json class some memory does not released by linux base OS.<br>
                // We release this memory every time use this method
                malloc_trim(0);  // Trim all memories
#endif
            } catch (std::exception& exception) {
                // ToDo: Generate a error and throw out a log message
                errorModelResult.Code = 1;
                errorModelResult.Message = "Error: " + std::string(exception.what());
                errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
            }
            if (ifStream.is_open()) {
                ifStream.close();
            }
            return errorModelResult;
        }
        template <class JsonableClass>
        model::ErrorModel ToJsonFile(const JsonableClass& jsonableClass, const std::string& jsonFilePath) {
            model::ErrorModel errorModelResult;
            std::ofstream ofStream(jsonFilePath);
            try {
                std::string jsonString;
                errorModelResult = ToJson(jsonableClass, jsonString);
                if (ofStream.is_open()) {
                    ofStream << jsonString;
                }
            } catch (std::exception& exception) {
                // ToDo: Generate a error and throw out a log message
                errorModelResult.Code = 1;
                errorModelResult.Message = "Error on : " + std::string(exception.what());
                errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
            }
            if (ofStream.is_open()) {
                ofStream.close();
            }
            return errorModelResult;
        }

        static model::ErrorModel FromJson(std::function<model::ErrorModel(model::Model&, nlohmann::ordered_json&)> const& fromJsonFunction, model::Model& model, nlohmann::ordered_json& json) {
            model::ErrorModel errorModelResult;
            try {
                errorModelResult = fromJsonFunction(model, json);
            } catch (std::exception& exception) {
                // ToDo: Generate a error and throw out a log message
                errorModelResult.Code = 1;
                errorModelResult.Message = "Error on : " + std::string(exception.what());
                errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
            }
            return errorModelResult;
        }
        static model::ErrorModel ToJson(std::function<model::ErrorModel(model::Model&, nlohmann::ordered_json&)> const& toJsonFunction, model::Model& model, nlohmann::ordered_json& json) {
            model::ErrorModel errorModelResult;
            try {
                errorModelResult = toJsonFunction(model, json);
            } catch (std::exception& exception) {
                // ToDo: Generate a error and throw out a log message
                errorModelResult.Code = 1;
                errorModelResult.Message = "Error on : " + std::string(exception.what());
                errorModelResult.Level = constant::ErrorLevel::ANAR_HIGH_WARNING;
            }
            return errorModelResult;
        }

        static model::ErrorModel FromJson(model::Model& model, nlohmann::ordered_json& json);
        static model::ErrorModel ToJson(const model::Model& model, nlohmann::ordered_json& json);

        static model::ErrorModel FromJson(model::ConstantModel& constantModel, nlohmann::ordered_json& json);
        static model::ErrorModel ToJson(const model::ConstantModel& constantModel, nlohmann::ordered_json& json);

        static model::ErrorModel FromJson(model::ErrorModel& errorModel, nlohmann::ordered_json& json);
        static model::ErrorModel ToJson(const model::ErrorModel& errorModel, nlohmann::ordered_json& json);
    };
}  // namespace anar::common::service

#endif  // ANAR_SERVICE_JSON_PARSER_HPP
