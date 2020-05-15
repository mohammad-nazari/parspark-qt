#include "printer.hpp"

namespace parspark::model {
   PrinterPtr Printer::Create() {
      return std::make_shared<Printer>();
   }
   Printer::Printer()
       : BaseModel("Printer") {
   }

   bool Printer::FromJson(const QVariantMap& json) {
      BaseModel::FromJson(json);
      m_enable = json["enable"].toBool();
      m_name = json["name"].toString();
      m_title = json["title"].toString();
      return true;
   }
   const QVariantMap Printer::ToJson() const {
      QVariantMap json = BaseModel::ToJson();
      json["enable"] = m_enable;
      json["name"] = m_name;
      json["title"] = m_title;
      return json;
   }
} // namespace parspark::model
