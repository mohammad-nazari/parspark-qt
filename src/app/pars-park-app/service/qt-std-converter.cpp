#include "qt-std-converter.hpp"

#include <QDebug>
#include <QJsonDocument>
#include <iostream>

namespace anar::parspark::service {
   QtStdConverter::QtStdConverter() = default;
   QtStdConverter::~QtStdConverter() = default;

   std::vector<std::string> QtStdConverter::QStringListToVector(const QStringList& qVector) {
      std::vector<std::string> stdVector;
      for (const auto& qItem : qVector) {
         stdVector.emplace_back(qItem.toStdString());
      }
      return stdVector;
   }
   QStringList QtStdConverter::VectorToQStringList(const std::vector<std::string>& stdVector) {
      QStringList qVector;
      for (const auto& qItem : stdVector) {
         qVector.push_back(qItem.c_str());
      }
      return qVector;
   }
   QVariant QtStdConverter::JsonToQVariant(const nlohmann::ordered_json& json) {
      QJsonParseError* jsonParseError = nullptr;
      QJsonDocument qJsonDocument = QJsonDocument::fromJson(json.dump().c_str(), jsonParseError);
      return qJsonDocument.toVariant();
   }
   nlohmann::ordered_json QtStdConverter::QVariantToJson(const QVariant& qVariant) {
      return nlohmann::ordered_json::parse(qVariant.toJsonDocument().toJson().toStdString());
   }
   QVariantMap QtStdConverter::JsonToQVariantMap(const nlohmann::ordered_json& json) {
      return JsonToQVariant(json).toMap();
   }
   nlohmann::ordered_json QtStdConverter::QVariantMapToJson(const QVariantMap& qVariantMap) {
      QJsonDocument qJson = QJsonDocument::fromVariant(qVariantMap);
      nlohmann::ordered_json json = nlohmann::ordered_json::parse(qJson.toJson().toStdString());
      return json;
   }
}  // namespace anar::common::service