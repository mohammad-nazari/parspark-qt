#include "card-reader.hpp"

namespace parspark::model {
   CardReader::CardReader()
       : BaseModel("CardReader") {
   }

   bool CardReader::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enter->FromJson(json["enter"].toMap());
      m_exit->FromJson(json["exit"].toMap());
      return true;
   }
   const QVariantMap CardReader::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enter"] = m_enter->ToJson();
      json["exit"] = m_exit->ToJson();
      return json;
   }
} // namespace parspark::model
