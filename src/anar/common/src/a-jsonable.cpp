#include "anar/a-jsonable.hpp"

#include <Poco/FileStream.h>

namespace anar::interfaces {
   AJsonable::AJsonable() = default;
   AJsonable::~AJsonable() = default;

   bool AJsonable::FromJsonString(const std::string& jsonString) {
      try {
         // Parse JSON format string to JSON document
         nlohmann::ordered_json json = nlohmann::ordered_json::parse(jsonString);
         // Read object data from JSON document
         bool result;// = FromJson(json);
#ifdef UNIX
         // In nlohman json class some memory does not released by linux base OS.<br>
         // We release this memory every time use this method
         malloc_trim(0);  // Trim all memories
#endif
         return result;
      } catch (std::exception& exception) {
      }
      return false;
   }
   std::string AJsonable::ToJsonString() {
      try {
         std::string result;// = ToJson().dump();
#ifdef UNIX
         // In nlohman json class some memory does not released by linux base OS.<br>
         // We release this memory every time use this method
         malloc_trim(0);  // Trim all memories
#endif
         return result;
      } catch (std::exception& exception) {
      }
   }

   bool AJsonable::FromJsonFile(const std::string& jsonFilePath) {
      Poco::FileStream fileStream(jsonFilePath, std::ios::in);
   }
   bool AJsonable::ToJsonFile(const std::string& jsonFilePath) {
      return false;
   }
}  // namespace anar::interfaces
