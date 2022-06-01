
#include "anar/string.hpp"

#include <Poco/MD5Engine.h>
#include <Poco/SHA1Engine.h>

namespace anar::common::service {
    String::String() = default;
    String::~String() = default;

    std::string String::MD5(const std::string &rawValue) {
        Poco::MD5Engine md5;
        md5.update(rawValue);
        return Poco::DigestEngine::digestToHex(md5.digest());
    }
    std::string String::SHA1(const std::string &rawValue) {
        Poco::SHA1Engine sha1Engine;
        sha1Engine.update(rawValue);
        return Poco::SHA2Engine::digestToHex(sha1Engine.digest());
    }
    std::string String::SHA224(const std::string &rawValue) {
        return sha2(rawValue, Poco::SHA2Engine::ALGORITHM::SHA_224);
    }
    std::string String::SHA256(const std::string &rawValue) {
        return sha2(rawValue, Poco::SHA2Engine::ALGORITHM::SHA_256);
    }
    std::string String::SHA384(const std::string &rawValue) {
        return sha2(rawValue, Poco::SHA2Engine::ALGORITHM::SHA_384);
    }
    std::string String::SHA512(const std::string &rawValue) {
        return sha2(rawValue, Poco::SHA2Engine::ALGORITHM::SHA_512);
    }
    std::string String::sha2(const std::string &rawValue, Poco::SHA2Engine::ALGORITHM algorithm) {
        Poco::SHA2Engine sha2Engine(algorithm);
        sha2Engine.update(rawValue);
        return Poco::SHA2Engine::digestToHex(sha2Engine.digest());
    }
}  // namespace anar::common::service