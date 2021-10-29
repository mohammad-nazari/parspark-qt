#include "qt-std-converter.hpp"

#include <QDebug>
#include <QJsonDocument>
#include <iostream>

namespace anar::service {
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
   QVariant QtStdConverter::JsonToQVariant(const json_nlohmann& json) {
      QJsonParseError* jsonParseError = nullptr;
      QJsonDocument qJsonDocument = QJsonDocument::fromJson(json.dump().c_str(), jsonParseError);
      return qJsonDocument.toVariant();
   }
   json_nlohmann QtStdConverter::QVariantToJson(const QVariant& qVariant) {
      return json_nlohmann::parse(qVariant.toJsonDocument().toJson().toStdString());
   }
   QVariantMap QtStdConverter::JsonToQVariantMap(const json_nlohmann& json) {
      return JsonToQVariant(json).toMap();
   }
   json_nlohmann QtStdConverter::QVariantMapToJson(const QVariantMap& qVariantMap) {
      QJsonDocument qJson = QJsonDocument::fromVariant(qVariantMap);
      json_nlohmann json = json_nlohmann::parse(qJson.toJson().toStdString());
      return json;
   }
}  // namespace anar::service