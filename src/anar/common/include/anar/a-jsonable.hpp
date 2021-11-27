#ifndef ANAR_INTERFACE_JSONABLE_HPP
#define ANAR_INTERFACE_JSONABLE_HPP

#include <nlohmann/fifo-map/fifo_map.hpp>
#include <nlohmann/json.hpp>

template <class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json_nlohmann = nlohmann::basic_json<my_workaround_fifo_map>;

namespace anar::interfaces {
   class AJsonable {
     public:
      AJsonable();
      virtual ~AJsonable();

      bool FromJsonString(const std::string& jsonString);
      std::string ToJsonString();

      bool FromJsonFile(const std::string& jsonFilePath);
      bool ToJsonFile(const std::string& jsonFilePath);
   };
}  // namespace anar::interfaces
#endif  // ANAR_INTERFACE_JSONABLE_HPP
