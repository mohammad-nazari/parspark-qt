#ifndef ANAR_STRINGABLE_HPP
#define ANAR_STRINGABLE_HPP

#include <string>

namespace anar::interfaces {
   class IStringable {
     public:
      IStringable();
      virtual ~IStringable();

      virtual bool FromString(const std::string& jsonString) = 0;
      virtual std::string ToString() = 0;
   };
}  // namespace anar::interface
#endif  // ANAR_STRINGABLE_HPP
