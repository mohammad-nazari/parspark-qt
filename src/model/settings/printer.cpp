#include "printer.hpp"

namespace anar::model {
   PrinterPtr Printer::Create() {
      return std::make_shared<Printer>();
   }
   Printer::Printer()
       : Model("Printer") {
   }

   bool Printer::FromJson(const json_nlohmann& json) {
      Model::FromJson(json);
      m_enable = json["enable"];
      m_name = json["name"];
      m_title = json["title"];
      return true;
   }
   json_nlohmann Printer::ToJson() {
      json_nlohmann json = Model::ToJson();
      json["enable"] = m_enable;
      json["name"] = m_name;
      json["title"] = m_title;
      return json;
   }
}  // namespace anar::model
