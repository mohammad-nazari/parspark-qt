#include "base-model.hpp"

#include <memory>

#include "Poco/UUIDGenerator.h"

namespace anar::model {
   BaseModelPtr BaseModel::Create(const std::string& name) {
      return std::make_shared<BaseModel>(name);
   }
   BaseModel::BaseModel(std::string name)
       : m_name(std::move(name)) {
      m_id = Poco::UUIDGenerator::defaultGenerator().create().toString();
   }

   bool BaseModel::FromJson(const json_nlohmann& json) {
      m_id = json["id"];
      m_name = json["name"];
      return true;
   }
   json_nlohmann BaseModel::ToJson() {
      json_nlohmann json;
      json["id"] = m_id;
      json["name"] = m_name;
      return json;
   }
}  // namespace anar::model
