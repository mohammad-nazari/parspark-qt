#ifndef ANAR_INTERFACE_JSONABLE_HPP
#define ANAR_INTERFACE_JSONABLE_HPP

#include <nlohmann/json.hpp>

namespace anar {
    namespace common {
        namespace interfaces {
            class AJsonable {
               public:
                AJsonable();
                virtual ~AJsonable();

                bool FromJsonString(const std::string& jsonString);
                std::string ToJsonString();

                bool FromJsonFile(const std::string& jsonFilePath);
                bool ToJsonFile(const std::string& jsonFilePath);
            };
        }  // namespace interfaces
    }      // namespace common
}  // namespace anar
#endif  // ANAR_INTERFACE_JSONABLE_HPP
