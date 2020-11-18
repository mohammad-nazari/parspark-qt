#include "i-a-jsonable.hpp"

namespace anar::interfaces {
   IAJsonable::IAJsonable() = default;
   IAJsonable::~IAJsonable() = default;

   bool IAJsonable::FromString(const std::string& jsonString) {
      try {
         // Parse JSON format string to JSON document
         json_nlohmann json = json_nlohmann::parse(jsonString);
         // Read object data from JSON document
         auto result = FromJson(json);
#ifdef UNIX
         // In nlohman json class some memory does not released by linux base OS.<br>
         // We release this memory every time use this method
         malloc_trim(0);  // Trim all memories
#endif
         return result;
      } catch (std::exception& ex) {
      }
      return false;
   }
   std::string IAJsonable::ToString() {
      auto result = ToJson().dump();
#ifdef UNIX
      // In nlohman json class some memory does not released by linux base OS.<br>
      // We release this memory every time use this method
      malloc_trim(0);  // Trim all memories
#endif
      return result;
   }

   bool IAJsonable::FromFile(const std::string& filePath) {
      return false;
   }
   bool IAJsonable::ToFile(const std::string& filePath) {
      return false;
   }
}  // namespace anar::interface
