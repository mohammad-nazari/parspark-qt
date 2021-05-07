#include "card-reader.hpp"

namespace anar::model {
   CardReaderPtr CardReader::Create() {
      return anar::model::CardReaderPtr();
   }
   CardReader::CardReader()
       : Model("CardReader") {
   }

   bool CardReader::FromJson(const json_nlohmann& json) {
      Model::FromJson(json);
      m_enter->FromJson(json["enter"]);
      m_exit->FromJson(json["exit"]);
      return true;
   }
   json_nlohmann CardReader::ToJson() {
      json_nlohmann json = Model::ToJson();
      json["enter"] = m_enter->ToJson();
      json["exit"] = m_exit->ToJson();
      return json;
   }
}  // namespace anar::model
