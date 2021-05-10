#ifndef ANAR_STRING_COMMON_HPP
#define ANAR_STRING_COMMON_HPP

#include <string>

#include "Poco/DigestStream.h"
#include "Poco/MD5Engine.h"
#include "Poco/SHA1Engine.h"
#include "Poco/SHA2Engine.h"

namespace anar::common {
   class String {
     public:
      String();
      virtual ~String();

      static std::string MD5(const std::string& rawValue);
      static std::string SHA1(const std::string& rawValue);
      static std::string SHA224(const std::string& rawValue);
      static std::string SHA256(const std::string& rawValue);
      static std::string SHA384(const std::string& rawValue);
      static std::string SHA512(const std::string& rawValue);

     private:
      static std::string sha2(const std::string& rawValue, Poco::SHA2Engine::ALGORITHM algorithm);
   };
}  // namespace anar::common
#endif  // ANAR_STRING_COMMON_HPP
