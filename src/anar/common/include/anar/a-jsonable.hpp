#ifndef ANAR_INTERFACE_JSONABLE_HPP
#define ANAR_INTERFACE_JSONABLE_HPP

#include <nlohmann/json.hpp>

namespace anar::common::interfaces {
    class AJsonable {
       public:
        AJsonable();
        virtual ~AJsonable();

        bool FromJsonString(const std::string& jsonString);
        std::string ToJsonString();

        bool FromJsonFile(const std::string& jsonFilePath);
        bool ToJsonFile(const std::string& jsonFilePath);
    };
}  // namespace anar::common::interfaces
#endif  // ANAR_INTERFACE_JSONABLE_HPP
