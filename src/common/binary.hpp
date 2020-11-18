#ifndef ANAR_BINARY_HPP
#define ANAR_BINARY_HPP

#include <cstdint>

namespace anar::common {
   class Binary {
     public:
      static uint64_t Reverse(const uint64_t& value,const  uint8_t& byteLen =1);
   };
}  // namespace anar::common
#endif  // ANAR_BINARY_HPP
