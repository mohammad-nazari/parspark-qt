#ifndef ANAR_JSONABLE_HPP
#define ANAR_JSONABLE_HPP

#include <nlohmann/fifo-map/fifo_map.hpp>
#include <nlohmann/json.hpp>
#include <string>

template <class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json_nlohmann = nlohmann::basic_json<my_workaround_fifo_map>;

namespace anar::interfaces {
   class AJsonable {
     public:
      AJsonable();
      virtual ~AJsonable();

      virtual bool FromJson(const json_nlohmann& json) = 0;
      [[nodiscard]] virtual json_nlohmann ToJson() = 0;

      bool FromJsonString(const std::string& jsonString);
      [[nodiscard]] std::string ToJsonString();

      bool FromJsonFile(const std::string& jsonFilePath);
      bool ToJsonFile(const std::string& jsonFilePath);
   };
}  // namespace anar::interfaces
#endif  // ANAR_JSONABLE_HPP
