#ifndef ANAR_SERVICE_STRING_HPP
#define ANAR_SERVICE_STRING_HPP

#include <Poco/SHA2Engine.h>

#include <string>

namespace anar::service {
   class String {
     public:
      String();
      virtual ~String();

      static std::string MD5(const std::string &rawValue);
      static std::string SHA1(const std::string &rawValue);
      static std::string SHA224(const std::string &rawValue);
      static std::string SHA256(const std::string &rawValue);
      static std::string SHA384(const std::string &rawValue);
      static std::string SHA512(const std::string &rawValue);

     private:
      static std::string sha2(const std::string &rawValue, Poco::SHA2Engine::ALGORITHM algorithm);
   };
}  // namespace anar::service
#endif  // ANAR_SERVICE_STRING_HPP
