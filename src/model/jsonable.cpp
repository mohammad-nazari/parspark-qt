#include "jsonable.hpp"

#include <QJsonDocument>
#include <QJsonValue>
#include <QVariantMap>
#include <QtDebug>

namespace parspark::model {
   Jsonable::Jsonable() {
   }

   bool Jsonable::FromString(const QString& jsonString) {
      QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
      return !jsonDoc.isEmpty() && FromJson(jsonDoc.toVariant().toMap());
   }

   const QString Jsonable::ToString() const {
      QJsonDocument jsonDoc = QJsonDocument::fromVariant(ToJson());
      return jsonDoc.toJson(QJsonDocument::Compact);
   }
} // namespace parspark::model
