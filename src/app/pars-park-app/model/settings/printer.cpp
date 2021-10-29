#include "printer.hpp"

namespace anar::model {
   PrinterPtr Printer::Create() {
      return std::make_shared<Printer>();
   }
   Printer::Printer()
       : Model("Printer") {
   }

   bool Printer::FromJson(const json_nlohmann& json) {

      m_enable = json["enable"];
      m_title = json["title"];
      return true;
   }
   json_nlohmann Printer::ToJson() {
      json_nlohmann json;
      json["enable"] = m_enable;
      json["title"] = m_title;
      return json;
   }
}  // namespace anar::model
