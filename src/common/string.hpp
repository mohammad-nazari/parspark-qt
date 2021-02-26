#ifndef ANAR_STRING_COMMON_HPP
#define ANAR_STRING_COMMON_HPP

#include <Poco/DigestStream.h>
#include <Poco/MD5Engine.h>

#include <string>

namespace anar::common {
   class String {
     public:
      String();
      virtual ~String();

      static std::string MD5(const std::string& rawValue);
   };
}  // namespace anar::common
#endif  // ANAR_STRING_COMMON_HPP
