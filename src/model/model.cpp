#include "model.hpp"

#include <memory>

namespace anar::model {
   ModelPtr Model::CreatePtr(const std::string& name, const std::string& description) {
      return std::make_shared<Model>(name, description);
   }
   Model Model::Create(const std::string& name, const std::string& description) {
      return Model(name, description);
   }
   Model::Model(std::string name, std::string description)
       : m_name(std::move(name))
       , m_description(std::move(description)) {
   }

   bool Model::FromJson(const json_nlohmann& json) {
      m_id = json["id"];
      m_name = json["name"];
      return true;
   }
   json_nlohmann Model::ToJson() {
      json_nlohmann json;
      json["id"] = m_id;
      json["name"] = m_name;
      return json;
   }
}  // namespace anar::model
