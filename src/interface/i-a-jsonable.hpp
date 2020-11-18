#ifndef ANAR_JSONABLE_HPP
#define ANAR_JSONABLE_HPP

#include <string>

#include "i-fileable.hpp"
#include "i-stringable.hpp"
#include "lib/nlohmann/fifo_map/src/fifo_map.hpp"
#include "lib/nlohmann/nlohmann_json/include/nlohmann/json.hpp"

template <class K, class V, class dummy_compare, class A>
using my_workaround_fifo_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using json_nlohmann = nlohmann::basic_json<my_workaround_fifo_map>;

namespace anar::interfaces {
   class IAJsonable
       : public IStringable
       , public IFileable {
     public:
      IAJsonable();
      ~IAJsonable() override;

      // Stringable interface
      bool FromString(const std::string& jsonString) override;
      std::string ToString() override;

      // Fileable interface
      bool FromFile(const std::string& filePath) override;
      bool ToFile(const std::string& filePath) override;

      virtual bool FromJson(const json_nlohmann& json) = 0;
      virtual json_nlohmann ToJson() = 0;
   };
}  // namespace anar::interfaces
#endif  // ANAR_JSONABLE_HPP
