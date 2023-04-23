#ifndef ANAR_SERVICE_BINARY_HPP
#define ANAR_SERVICE_BINARY_HPP

#include <cstdint>

namespace anar::common::service {
    class Binary {
       public:
        static uint64_t Reverse(const uint64_t &value, const uint8_t &byteLen = 1);
    };
}  // namespace anar::common::service
#endif  // ANAR_SERVICE_BINARY_HPP
