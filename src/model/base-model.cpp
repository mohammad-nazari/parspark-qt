#include "base-model.hpp"

#include <QJsonValue>
#include <QUuid>
#include <QtDebug>

namespace parspark::model {
   BaseModelPtr BaseModel::Create(const QString& name) {
      return std::make_shared<BaseModel>(name);
   }

   BaseModel::BaseModel(const QString& name)
       : m_name(name) {
      m_id = QUuid().createUuid().toString();
   }

   bool BaseModel::FromJson(const QVariantMap& json) {
      m_id = json["id"].toString();
      m_name = json["name"].toString();
      return true;
   }
   const QVariantMap BaseModel::ToJson() const {
      QVariantMap json;
      json["id"] = m_id;
      json["name"] = m_name;
      return json;
   }

   QString BaseModel::Id() const {
      return m_id;
   }
   void BaseModel::Id(const QString& id) {
      m_id = id;
   }
   QString BaseModel::Name() const {
      return m_name;
   }
   void BaseModel::Name(const QString& name) {
      m_name = name;
   }
} // namespace parspark::model
