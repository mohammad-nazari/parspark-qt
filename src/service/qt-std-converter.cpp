#include "qt-std-converter.hpp"

#include <QJsonDocument>

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
   QVariant QtStdConverter::JsonToQVariant(const nlohmann::basic_json<>& json) {
      QJsonDocument qJsonDocument = QJsonDocument::fromJson(json.dump().c_str());
      return QVariant(qJsonDocument);
   }
   nlohmann::basic_json<> QtStdConverter::QVariantToJson(const QVariant& qVariant) {
      return nlohmann::basic_json<>::parse(qVariant.toJsonDocument().toJson().toStdString());
   }
   QVariantMap QtStdConverter::JsonToQVariantMap(const nlohmann::basic_json<>& json) {
      return JsonToQVariant(json).toMap();
   }
   nlohmann::basic_json<> QtStdConverter::QVariantMapToJson(const QVariantMap& qVariantMap) {
      nlohmann::basic_json<> json;
      for(const auto& variant: qVariantMap.toStdMap()){
         json[variant.first.toStdString()] = QVariantToJson(variant.second);
      }
      return json;
   }
}  // namespace anar::common