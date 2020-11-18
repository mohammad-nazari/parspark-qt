#include "string.hpp"

namespace anar::common {
   String::String() = default;
   String::~String() = default;

   std::string String::MD5(const std::string& rawValue) {
      Poco::MD5Engine md5;
      Poco::DigestOutputStream ds(md5);
      ds << rawValue;
      ds.close();
      std::string passWord = Poco::DigestEngine::digestToHex(md5.digest());
      return passWord;
   }
}  // namespace anar::common