#ifndef ANAR_PARS_PARK_SERVICE_QT_STD_CONVERTER_HPP
#define ANAR_PARS_PARK_SERVICE_QT_STD_CONVERTER_HPP

#include <QStringList>
#include <QVariant>
#include <QVector>
#include <vector>

#include "anar/a-jsonable.hpp"

namespace anar::parspark::service {
   class QtStdConverter {
     public:
      QtStdConverter();
      virtual ~QtStdConverter();

      template <typename Temp>
      static std::vector<Temp> QVectorToVector(const QVector<Temp>& qVector);
      template <typename Temp>
      static QVector<Temp> VectorToQVector(const std::vector<Temp>& stdVector);

      static std::vector<std::string> QStringListToVector(const QStringList& qVector);
      static QStringList VectorToQStringList(const std::vector<std::string>& stdVector);

      static QVariant JsonToQVariant(const nlohmann::ordered_json& json);
      static nlohmann::ordered_json QVariantToJson(const QVariant& qVariant);
      static QVariantMap JsonToQVariantMap(const nlohmann::ordered_json& json);
      static nlohmann::ordered_json QVariantMapToJson(const QVariantMap& qVariantMap);
   };
   template <typename Temp>
   std::vector<Temp> QtStdConverter::QVectorToVector(const QVector<Temp>& qVector) {
      std::vector<Temp> stdVector;
      for (const auto& qItem : qVector) {
         stdVector.emplace_back(qItem);
      }
      return stdVector;
   }
   template <typename Temp>
   QVector<Temp> QtStdConverter::VectorToQVector(const std::vector<Temp>& stdVector) {
      QVector<Temp> qVector;
      for (const auto& qItem : stdVector) {
         qVector.emplace_back(qItem);
      }
      return qVector;
   }
}  // namespace anar::parspark::service
#endif  // ANAR_PARS_PARK_SERVICE_QT_STD_CONVERTER_HPP
